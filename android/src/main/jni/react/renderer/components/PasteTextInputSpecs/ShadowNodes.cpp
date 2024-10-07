
/**
 * This code was generated by [react-native-codegen](https://www.npmjs.com/package/react-native-codegen).
 *
 * Do not edit this file as changes may cause incorrect behavior and will be lost
 * once the code is regenerated.
 *
 * @generated by codegen project: GenerateShadowNodeCpp.js
 */

#include "ShadowNodes.h"
#include "States.h"

#include <react/renderer/core/LayoutConstraints.h>
#include <react/renderer/core/LayoutContext.h>
#include <react/renderer/core/conversions.h>

#include <react/featureflags/ReactNativeFeatureFlags.h>
#include <react/jni/ReadableNativeMap.h>
#include <react/renderer/attributedstring/AttributedStringBox.h>
#include <react/renderer/attributedstring/TextAttributes.h>
#include <react/renderer/components/text/BaseTextShadowNode.h>
#include <react/renderer/core/LayoutConstraints.h>
#include <react/renderer/core/LayoutContext.h>
#include <react/renderer/core/conversions.h>
#include <react/renderer/textlayoutmanager/TextLayoutContext.h>

namespace facebook::react {

extern const char PasteTextInputComponentName[] = "PasteTextInput";

PasteTextInputShadowNode::PasteTextInputShadowNode(
        const ShadowNode& sourceShadowNode,
        const ShadowNodeFragment& fragment)
        : ConcreteViewShadowNode(sourceShadowNode, fragment) {
    auto& sourcePasteTextInputShadowNode =
        static_cast<const PasteTextInputShadowNode&>(sourceShadowNode);

    if (ReactNativeFeatureFlags::enableCleanTextInputYogaNode()) {
        if (!fragment.children && !fragment.props &&
            sourcePasteTextInputShadowNode.getIsLayoutClean()) {
            // This ParagraphShadowNode was cloned but did not change
            // in a way that affects its layout. Let's mark it clean
            // to stop Yoga from traversing it.
            cleanLayout();
        }
    }
}

void PasteTextInputShadowNode::setContextContainer(
        facebook::react::ContextContainer *contextContainer) {
    ensureUnsealed();
    contextContainer_ = contextContainer;
}

AttributedString PasteTextInputShadowNode::getAttributedString() const {
    auto childTextAttributes = TextAttributes::defaultTextAttributes();
    childTextAttributes.apply(getConcreteProps().textAttributes);

    auto attributedString = AttributedString{};
    auto attachments = BaseTextShadowNode::Attachments{};
    BaseTextShadowNode::buildAttributedString(
            childTextAttributes, *this, attributedString, attachments);

    if (!getConcreteProps().text.empty()) {
        auto textAttributes = TextAttributes::defaultTextAttributes();
        auto fragment = AttributedString::Fragment{};
        fragment.string = getConcreteProps().text;
        fragment.textAttributes = textAttributes;
        fragment.textAttributes.backgroundColor = clearColor();
        fragment.parentShadowView = ShadowView(*this);
        attributedString.prependFragment(fragment);
    }
    return attributedString;
}

AttributedString PasteTextInputShadowNode::getPlaceholderAttributedString() const {
    // Return placeholder text, since text and children are empty.
    auto textAttributedString = AttributedString{};
    auto fragment = AttributedString::Fragment{};
    fragment.string = getConcreteProps().placeholder;

    if (fragment.string.empty()) {
        fragment.string = BaseTextShadowNode::getEmptyPlaceholder();
    }

    auto textAttributes = TextAttributes::defaultTextAttributes();
    textAttributes.apply(getConcreteProps().textAttributes);

    // If there's no text, it's possible that this Fragment isn't actually
    // appended to the AttributedString (see implementation of appendFragment)
    fragment.textAttributes = textAttributes;
    fragment.parentShadowView = ShadowView(*this);
    textAttributedString.appendFragment(fragment);

    return textAttributedString;
}

AttributedString PasteTextInputShadowNode::getMostRecentAttributedString() const {
    const auto& state = getStateData();

    auto reactTreeAttributedString = getAttributedString();

    // Sometimes the treeAttributedString will only differ from the state
    // not by inherent properties (string or prop attributes), but by the frame of
    // the parent which has changed Thus, we can't directly compare the entire
    // AttributedString
    bool treeAttributedStringChanged =
            !state.reactTreeAttributedString.compareTextAttributesWithoutFrame(
                    reactTreeAttributedString);

    return (
            !treeAttributedStringChanged ? state.attributedString
                                         : reactTreeAttributedString);
}

void PasteTextInputShadowNode::updateStateIfNeeded() {
    ensureUnsealed();

    auto reactTreeAttributedString = getAttributedString();
    const auto& state = getStateData();

    // Tree is often out of sync with the value of the TextInput.
    // This is by design - don't change the value of the TextInput in the State,
    // and therefore in Java, unless the tree itself changes.
    if (state.reactTreeAttributedString == reactTreeAttributedString) {
        return;
    }

    // If props event counter is less than what we already have in state, skip it
    if (getConcreteProps().mostRecentEventCount < state.mostRecentEventCount) {
        return;
    }

    // Even if we're here and updating state, it may be only to update the layout
    // manager If that is the case, make sure we don't update text: pass in the
    // current attributedString unchanged, and pass in zero for the "event count"
    // so no changes are applied There's no way to prevent a state update from
    // flowing to Java, so we just ensure it's a noop in those cases.
    auto newEventCount =
            state.reactTreeAttributedString.isContentEqual(reactTreeAttributedString)
            ? 0
            : getConcreteProps().mostRecentEventCount;
    auto newAttributedString = getMostRecentAttributedString();

    setStateData(PasteTextInputState{
            newEventCount,
            newAttributedString,
            reactTreeAttributedString,
            state.paragraphAttributes,
            state.defaultThemePaddingStart,
            state.defaultThemePaddingEnd,
            state.defaultThemePaddingTop,
            state.defaultThemePaddingBottom});
}

Size PasteTextInputShadowNode::measureContent(
        const LayoutContext& layoutContext,
        const LayoutConstraints& layoutConstraints) const {
    if (getStateData().cachedAttributedStringId != 0) {
        return textLayoutManager_
                ->measureCachedSpannableById(
                        getStateData().cachedAttributedStringId,
                        getConcreteProps().paragraphAttributes,
                        layoutConstraints)
                .size;
    }

    // Layout is called right after measure.
    // Measure is marked as `const`, and `layout` is not; so State can be updated
    // during layout, but not during `measure`. If State is out-of-date in layout,
    // it's too late: measure will have already operated on old State. Thus, we
    // use the same value here that we *will* use in layout to update the state.
    AttributedString attributedString = getMostRecentAttributedString();

    if (attributedString.isEmpty() && getStateData().mostRecentEventCount != 0) {
        return {0, 0};
    }

    TextLayoutContext textLayoutContext;
    textLayoutContext.pointScaleFactor = layoutContext.pointScaleFactor;
    return textLayoutManager_
            ->measure(
                    AttributedStringBox{attributedString},
                    getConcreteProps().paragraphAttributes,
                    textLayoutContext,
                    layoutConstraints)
            .size;
}

void PasteTextInputShadowNode::layout(facebook::react::LayoutContext layoutContext) {
    updateStateIfNeeded();
    ConcreteViewShadowNode::layout(layoutContext);
}

void PasteTextInputShadowNode::setTextLayoutManager(SharedTextLayoutManager textLayoutManager) {
    ensureUnsealed();
    textLayoutManager_ = textLayoutManager;
}

} // namespace facebook::react
