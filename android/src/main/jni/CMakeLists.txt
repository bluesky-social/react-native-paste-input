# Copyright (c) Meta Platforms, Inc. and affiliates.
#
# This source code is licensed under the MIT license found in the
# LICENSE file in the root directory of this source tree.

cmake_minimum_required(VERSION 3.13)
set(CMAKE_VERBOSE_MAKEFILE on)

file(GLOB react_codegen_SRCS CONFIGURE_DEPENDS *.cpp react/renderer/components/PasteTextInputSpecs/*.cpp)

add_library(
  react_codegen_PasteTextInputSpecs
  OBJECT
  ${react_codegen_SRCS}
)

target_include_directories(react_codegen_PasteTextInputSpecs PUBLIC . react/renderer/components/PasteTextInputSpecs)

target_link_libraries(
  react_codegen_PasteTextInputSpecs
  fbjni
  folly_runtime
  glog
  jsi
  react_codegen_rncore
  react_debug
  react_nativemodule_core
  react_featureflags
  react_render_textlayoutmanager
  react_render_componentregistry
  react_render_core
  react_render_debug
  react_render_graphics
  react_render_imagemanager
  react_render_mapbuffer
  react_utils
  rrc_view
  rrc_text
  rrc_textinput
  rrc_image
  yoga
)

target_compile_options(
  react_codegen_PasteTextInputSpecs
  PRIVATE
  -DLOG_TAG=\"PasteTextInput\"
  -fexceptions
  -frtti
  -std=c++20
  -Wall
)
