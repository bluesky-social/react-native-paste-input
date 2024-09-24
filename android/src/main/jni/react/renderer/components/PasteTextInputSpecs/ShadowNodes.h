
/**
 * This code was generated by [react-native-codegen](https://www.npmjs.com/package/react-native-codegen).
 *
 * Do not edit this file as changes may cause incorrect behavior and will be lost
 * once the code is regenerated.
 *
 * @generated by codegen project: GenerateShadowNodeH.js
 */

#pragma once

#include "EventEmitters.h"
#include "Props.h"
#include "States.h"
//#include <react/renderer/components/view/ConcreteViewShadowNode.h>
//#include <react/renderer/textlayoutmanager/TextLayoutContext.h>
//#include <jsi/jsi.h>
#include <react/renderer/components/androidtextinput/AndroidTextInputShadowNode.h>
#include <react/renderer/components/androidtextinput/AndroidTextInputState.h>

namespace facebook::react {

JSI_EXPORT extern const char PasteTextInputComponentName[];

/*
 * `ShadowNode` for <PasteTextInput> component.
 */
class PasteTextInputShadowNode final : public ConcreteViewShadowNode<
    PasteTextInputComponentName,
    PasteTextInputProps,
    PasteTextInputEventEmitter,
    PasteTextInputState,
    true> {
public:
    static ShadowNodeTraits BaseTraits() {
        auto traits = ConcreteViewShadowNode::BaseTraits();
        traits.set(ShadowNodeTraits::Trait::LeafYogaNode);
        return traits;
    }

    using ConcreteViewShadowNode::ConcreteViewShadowNode;

    PasteTextInputShadowNode(
        const ShadowNode& sourceShadowNode,
        const ShadowNodeFragment& fragment);

    void setContextContainer(
        ContextContainer *contextContainer
    );

    AttributedString getAttributedString() const;
    AttributedString getPlaceholderAttributedString() const;

    void setTextLayoutManager(SharedTextLayoutManager textLayoutManager);

private:
    ContextContainer *contextContainer_;

    AttributedString getMostRecentAttributedString() const;

    void updateStateIfNeeded();

    SharedTextLayoutManager textLayoutManager_;

    void layout(LayoutContext layoutContext) override;

    mutable std::optional<AttributedString> cachedAttributedString_{};
};

} // namespace facebook::react
