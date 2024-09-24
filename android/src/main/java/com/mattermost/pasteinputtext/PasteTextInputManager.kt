package com.mattermost.pasteinputtext

import android.os.Build
import android.text.InputType
import android.util.Log
import com.facebook.react.bridge.ReactApplicationContext
import com.facebook.react.bridge.ReactContext
import com.facebook.react.common.MapBuilder
import com.facebook.react.common.mapbuffer.MapBuffer
import com.facebook.react.module.annotations.ReactModule
import com.facebook.react.uimanager.ReactStylesDiffMap
import com.facebook.react.uimanager.StateWrapper
import com.facebook.react.uimanager.ThemedReactContext
import com.facebook.react.uimanager.UIManagerHelper
import com.facebook.react.uimanager.annotations.ReactProp
import com.facebook.react.uimanager.events.EventDispatcher
import com.facebook.react.views.text.TextLayoutManager
import com.facebook.react.views.textinput.ReactEditText
import com.facebook.react.views.textinput.ReactTextInputManager

@ReactModule(name = "PasteTextInput")
class PasteTextInputManager(context: ReactApplicationContext) : ReactTextInputManager() {
  private var disableCopyPaste: Boolean = false
  private val mContext = context

  override fun getName(): String = NAME

  @ReactProp(name = "disableCopyPaste", defaultBoolean = false)
  fun setDisableCopyPaste(editText: PasteInputEditText, disabled: Boolean) {
    disableCopyPaste = disabled
    val eventDispatcher = getEventDispatcher(mContext, editText)
    editText.customInsertionActionModeCallback = PasteInputActionCallback(editText, disabled, eventDispatcher)
    editText.customSelectionActionModeCallback = PasteInputActionCallback(editText, disabled, eventDispatcher)
    editText.setDisableCopyPaste(disabled)
  }

  private fun getEventDispatcher(reactContext: ReactContext, editText: ReactEditText): EventDispatcher? {
    return UIManagerHelper.getEventDispatcherForReactTag(reactContext, editText.id)
  }

  override fun updateState(
    view: ReactEditText,
    props: ReactStylesDiffMap?,
    stateWrapper: StateWrapper?
  ): Any? {
//    stateWrapper?.stateData?.getInt("mostRecentEventCount")?.let {
//      Log.d("PasteTextInputManager", "mostRecentEventCount: $it")
//    }
    val buffer = stateWrapper?.stateDataMapBuffer
    buffer?.count.let {
      Log.d("PasteTextInputManager", "buffer count: $it")
    }
    return super.updateState(view, props, stateWrapper)
  }

  override fun createViewInstance(context: ThemedReactContext): PasteInputEditText {
    val editText = PasteInputEditText(context)
    val inputType = editText.inputType

    editText.inputType = inputType and (InputType.TYPE_TEXT_FLAG_MULTI_LINE.inv())
    editText.returnKeyType = "done"
    val eventDispatcher = getEventDispatcher(mContext, editText)
    editText.customInsertionActionModeCallback = PasteInputActionCallback(editText, disableCopyPaste, eventDispatcher)
    editText.customSelectionActionModeCallback = PasteInputActionCallback(editText, disableCopyPaste, eventDispatcher)

    return editText
  }

  override fun addEventEmitters(reactContext: ThemedReactContext, editText: ReactEditText) {
    super.addEventEmitters(reactContext, editText)

    val pasteInputEditText = editText as PasteInputEditText
    val eventDispatcher = getEventDispatcher(reactContext, editText)
    pasteInputEditText.setOnPasteListener(PasteInputListener(pasteInputEditText, reactContext.surfaceId), eventDispatcher)
  }

  override fun getExportedCustomBubblingEventTypeConstants(): MutableMap<String, Any> {
    val map = super.getExportedCustomBubblingEventTypeConstants()!!
    map["onPaste"] = MapBuilder.of(
      "phasedRegistrationNames",
      MapBuilder.of("bubbled", "onPaste")
    )

    return map
  }

  override fun getReactTextUpdate(
    view: ReactEditText?,
    props: ReactStylesDiffMap?,
    state: MapBuffer?
  ): Any? {
    if (state!!.count == 0) {
      Log.d("PasteTextInputManager", "getReactTextUpdate: state count is 0")
      return null
    } else {
      Log.d("PasteTextInputManager", "it was there!")
      val attributedString = state!!.getMapBuffer(0)
      val paragraphAttributes = state!!.getMapBuffer(1)
      val spanned = TextLayoutManager.getOrCreateSpannableForText(
        view!!.context, attributedString,
        this.mReactTextViewManagerCallback
      )
    }

    val update = super.getReactTextUpdate(view, props, state)
    return update
  }

  companion object {
    const val NAME = "PasteTextInput"
    const val CACHE_DIR_NAME = "mmPasteInput"
  }
}
