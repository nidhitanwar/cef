// Copyright (c) 2013 The Chromium Embedded Framework Authors. All rights
// reserved. Use of this source code is governed by a BSD-style license that
// can be found in the LICENSE file.

#include "cefsimple/simple_app.h"

#include <string>
#include <iostream>
#include "cefsimple/simple_handler.h"
#include "include/cef_browser.h"
#include "include/cef_command_line.h"
#include "include/wrapper/cef_helpers.h"
using namespace std;
SimpleApp::SimpleApp() {
}



void SimpleApp::OnContextInitialized() {
  CEF_REQUIRE_UI_THREAD();
  cout << "In context Initialized";
  // Information used when creating the native window.
  CefWindowInfo window_info;
  RECT rect;
  rect.bottom = 230;
  rect.top = 30;
  rect.left = 20;
  rect.right = 180;
#if defined(OS_WIN)
 
window_info.SetAsPopup(NULL, "html");
 
#endif

  // SimpleHandler implements browser-level callbacks.
  CefRefPtr<SimpleHandler> handler(new SimpleHandler());

  // Specify CEF browser settings here.
  CefBrowserSettings browser_settings;

  std::string url;

  // Check if a "--url=" value was provided via the command-line. If so, use
  // that instead of the default URL.
  CefRefPtr<CefCommandLine> command_line =
      CefCommandLine::GetGlobalCommandLine();
 
  url = command_line->GetSwitchValue("url");
  if (url.empty())
    url ="www.google.com";

  // Create the first browser window.
  CefBrowserHost::CreateBrowserSync(window_info, handler.get(), url,
                                browser_settings, NULL);
}
