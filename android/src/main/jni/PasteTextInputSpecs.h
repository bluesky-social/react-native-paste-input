#pragma once

#include <ReactCommon/JavaTurboModule.h>
#include <ReactCommon/TurboModule.h>
#include <jsi/jsi.h>
#include <react/renderer/components/PasteTextInputSpecs/ComponentDescriptors.h>

namespace facebook {
namespace react {

class JSI_EXPORT PasteTextInputSpecsJSI : public JavaTurboModule {
public:
  PasteTextInputSpecsJSI(const JavaTurboModule::InitParams &params);
};

JSI_EXPORT
std::shared_ptr<TurboModule> PasteTextInputSpecs_ModuleProvider(const std::string &moduleName, const JavaTurboModule::InitParams &params);

} // namespace react
} // namespace facebook
