
/**
 * This code was generated by [react-native-codegen](https://www.npmjs.com/package/react-native-codegen).
 *
 * Do not edit this file as changes may cause incorrect behavior and will be lost
 * once the code is regenerated.
 *
 * @generated by codegen project: GenerateStateCpp.js
 */
#include "States.h"

#include <react/renderer/components/text/conversions.h>
#include <react/renderer/debug/debugStringConvertibleUtils.h>
#include <react/renderer/mapbuffer/MapBuffer.h>
#include <react/renderer/mapbuffer/MapBufferBuilder.h>

#include <utility>

namespace facebook::react {
//    PasteTextInputState::PasteTextInputState(
//            int64_t mostRecentEventCount,
//            int64_t cachedAttributedStringId,
//            AttributedString attributedString,
//            AttributedString reactTreeAttributedString,
//            ParagraphAttributes paragraphAttributes)
//            : mostRecentEventCount(mostRecentEventCount),
//              cachedAttributedStringId(cachedAttributedStringId),
//              attributedString(std::move(attributedString)),
//              reactTreeAttributedString(std::move(reactTreeAttributedString)),
//              paragraphAttributes(std::move(paragraphAttributes)) {}
//
//    folly::dynamic PasteTextInputState::getDynamic() const {
//        // Java doesn't need all fields, so we don't pass them all along.
//        folly::dynamic newState = folly::dynamic::object();
//
//        // If we have a `cachedAttributedStringId` we know that we're (1) not trying
//        // to set a new string, so we don't need to pass it along; (2) setState was
//        // called from Java to trigger a relayout with a `cachedAttributedStringId`,
//        // so Java has all up-to-date information and we should pass an empty map
//        // through.
//        if (cachedAttributedStringId == 0) {
//            newState["mostRecentEventCount"] = mostRecentEventCount;
////            newState["attributedString"] = toDynamic(attributedString);
////            newState["hash"] = newState["attributedString"]["hash"];
////            newState["paragraphAttributes"] =
////                    toDynamic(paragraphAttributes); // TODO: can we memoize this in Java?
//        }
//        return newState;
//    }
//
//    MapBuffer PasteTextInputState::getMapBuffer() const {
//        auto builder = MapBufferBuilder();
//        // See comment in getDynamic block.
//        if (cachedAttributedStringId == 0) {
//            // TODO truncation
//            builder.putInt(
//                    TX_STATE_KEY_MOST_RECENT_EVENT_COUNT,
//                    static_cast<int32_t>(mostRecentEventCount));
//
//            auto attStringMapBuffer = toMapBuffer(attributedString);
//            builder.putMapBuffer(TX_STATE_KEY_ATTRIBUTED_STRING, attStringMapBuffer);
//            auto paMapBuffer = toMapBuffer(paragraphAttributes);
//            builder.putMapBuffer(TX_STATE_KEY_PARAGRAPH_ATTRIBUTES, paMapBuffer);
//
//            builder.putInt(TX_STATE_KEY_HASH, attStringMapBuffer.getInt(AS_KEY_HASH));
//        }
//        return builder.build();
//    }
//
//    PasteTextInputState::PasteTextInputState(const PasteTextInputState &previousState,
//                                             const folly::dynamic &data)
//                                             :
//                                             mostRecentEventCount(
//                                                     data.getDefault("mostRecentEventCount", previousState.mostRecentEventCount).getInt()),
//                                                cachedAttributedStringId(
//                                                        data.getDefault("cachedAttributedStringId", previousState.cachedAttributedStringId).getInt()),
//                                                attributedString(
//                                                        data.getDefault("attributedString", previousState.attributedString).getString()),
//                                                reactTreeAttributedString(
//                                                        data.getDefault("reactTreeAttributedString", previousState.reactTreeAttributedString).getString()),
//                                                paragraphAttributes(
//                                                        data.getDefault("paragraphAttributes", previousState.paragraphAttributes).getString()) {}
} // namespace facebook::react
