
/**
 * This code was generated by [react-native-codegen](https://www.npmjs.com/package/react-native-codegen).
 *
 * Do not edit this file as changes may cause incorrect behavior and will be lost
 * once the code is regenerated.
 *
 * @generated by codegen project: GenerateEventEmitterH.js
 */
#pragma once

#include <react/renderer/components/view/ViewEventEmitter.h>


namespace facebook::react {
class PasteTextInputEventEmitter : public ViewEventEmitter {
 public:
  using ViewEventEmitter::ViewEventEmitter;

  struct OnBlur {
      int target;
    };

  struct OnChange {
      int target;
    int eventCount;
    std::string text;
    };

  struct OnChangeText {
      int target;
    int eventCount;
    std::string text;
    };

  struct OnEndEditing {
      int target;
    std::string text;
    };

  struct OnFocus {
      int target;
    };

  struct OnKeyPress {
      int target;
    std::string key;
    };

  struct OnPasteData {
      std::string fileName;
    int fileSize;
    std::string type;
    std::string uri;
    };

  struct OnPasteError {
      std::string message;
    };

  struct OnPaste {
      std::vector<OnPasteData> data;
    OnPasteError error;
    };

  struct OnSubmitEdition {
      int target;
    std::string text;
    };

  struct OnContentSizeChangeContentSize {
      int width;
    int height;
    };

  struct OnContentSizeChange {
      int target;
    OnContentSizeChangeContentSize contentSize;
    };

  struct OnScrollContentInset {
      double top;
    double bottom;
    double left;
    double right;
    };

  struct OnScrollContentOffset {
      double x;
    double y;
    };

  struct OnScrollContentSize {
      double width;
    double height;
    };

  struct OnScrollLayoutMeasurement {
      double width;
    double height;
    };

  struct OnScrollVelocity {
      double x;
    double y;
    };

  struct OnScroll {
      int target;
    OnScrollContentInset contentInset;
    OnScrollContentOffset contentOffset;
    OnScrollContentSize contentSize;
    OnScrollLayoutMeasurement layoutMeasurement;
    bool responderIgnoreScroll;
    OnScrollVelocity velocity;
    };

  struct OnSelectionChangeSelection {
      int start;
    int end;
    };

  struct OnSelectionChange {
      int target;
    OnSelectionChangeSelection selection;
    };

  struct OnTextInputRange {
      int start;
    int end;
    };

  struct OnTextInput {
      int target;
    std::string text;
    std::string previousText;
    OnTextInputRange range;
    };
  void onBlur(OnBlur value) const;

  void onChange(OnChange value) const;

  void onChangeText(OnChangeText value) const;

  void onEndEditing(OnEndEditing value) const;

  void onFocus(OnFocus value) const;

  void onKeyPress(OnKeyPress value) const;

  void onPaste(OnPaste value) const;

  void onSubmitEdition(OnSubmitEdition value) const;

  void onContentSizeChange(OnContentSizeChange value) const;

  void onScroll(OnScroll value) const;

  void onSelectionChange(OnSelectionChange value) const;

  void onTextInput(OnTextInput value) const;
};
} // namespace facebook::react
