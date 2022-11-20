 Copyright (C) 2011 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

// recovery UI definitions for mr recovery

#ifndef _RECOVERY_UI_H
#define _RECOVERY_UI_H

#include "minui/minui.h"

#define ITEM_MARGIN 10


#ifndef RECOVERY_UI_H
#define RECOVERY_UI_H

#include <linux/input.h>
#include <pthread.h>
#include <time.h>

#include <string>

// Abstract class for controlling the user interface during recovery.
class RecoveryUI {
  public:
    RecoveryUI() : key_queue_(), key_queue_len_(0), key_queue_head_(0), key_queue_tail_(0) { }
    virtual ~RecoveryUI() { }

    // Initialize the UI.  Returns 0 on success.
    virtual int Init() = 0;

    // Load a bitmap from the resource file and return a gr_surface.
    virtual gr_surface LoadBitmap(const char* filename) = 0;

    // Set the locale to use for text translation.
    virtual void SetLocale(const char* locale) = 0;

    // Set the background image to use.
    virtual void SetBackground(Icon icon) = 0;

    // Set the current progress bar position.
    virtual void ShowProgress(float portion, float seconds) = 0;

    // Set the current text to show.
    virtual void SetProgressType(ProgressType type) = 0;

    // Set the stage of the current operation.
    virtual void ShowStage(int current, int max) = 0;

    // Set the current text to show.
    virtual void SetText(const char* text) = 0;

    // Set the current text to show, and the color to use.
    virtual void SetTextColour(RecoveryUI::Colour colour) = 0;

    // Set the current icon to show.
    virtual void SetIcon(Icon icon) = 0;

    // Set the current install stage.
    virtual void ShowText(bool visible) = 0;

    // Set the current install stage.
    virtual void SetStage(int current, int max) = 0;

    // Set the current install stage.
    virtual void SetInstallStage(const char* stage) = 0;

    // Set the current install stage.
    virtual void SetError(const char* error) = 0;

    // Set the current install stage.
    virtual void SetErrorType(ErrorType type) = 0;

    // Set the current install stage.
    virtual void SetSystemUpdateText(bool security_update) = 0;

    // Set the current install stage.
    virtual void SetSystemUpdateText(bool security_update, int seconds) = 0;

    // Set the current install stage.
    virtual void SetSystemUpdateText(bool security_update, int seconds, bool wipe_cache) = 0;

    // Set the current install stage.
    virtual void SetSystemUpdateText
        (bool security_update, int seconds, bool wipe_cache, bool backup) = 0;

    // Set the current install stage.
    virtual void SetSystemUpdateText
        (bool security_update, int seconds, bool wipe_cache, bool backup, bool wipe_data) = 0;

        // define tzhe rets of the ui
    enum UIResult {
        NONE = 0,
        REFRESH = 1,
        EXIT = 2,
        KEY = 3,
        ERROR = 4,
    };

    // Wait for a key to be pressed, and return it.
      virtual int WaitKey() = 0;

      //show the menu
        virtual int ShowMenu() = 0;

        //define the menu items
        enum MenuItem {
            ITEM_REBOOT = 0,
            ITEM_APPLY_SDCARD = 1,
            ITEM_APPLY_CACHE = 2,
            ITEM_WIPE_DATA = 3,
            ITEM_WIPE_CACHE = 4,
            ITEM_NANDROID = 5,
            ITEM_PARTITION = 6,
            ITEM_ADVANCED = 7,
            ITEM_POWEROFF = 8,
            ITEM_REBOOT_RECOVERY = 9,
            ITEM_REBOOT_BOOTLOADER = 10,
            ITEM_APPLY_SDCARD2 = 11,
            ITEM_APPLY_CACHE2 = 12,
            ITEM_WIPE_DATA2 = 13,
            ITEM_WIPE_CACHE2 = 14,
            ITEM_NANDROID2 = 15,
            ITEM_PARTITION2 = 16,
            ITEM_ADVANCED2 = 17,
            ITEM_POWEROFF2 = 18,
            ITEM_REBOOT_RECOVERY2 = 19,
            ITEM_REBOOT_BOOTLOADER2 = 20,
            ITEM_APPLY_SDCARD3 = 21,
            ITEM_APPLY_CACHE3 = 22,
            ITEM_WIPE_DATA3 = 23,
            ITEM_WIPE_CACHE3 = 24,
            ITEM_NANDROID3 = 25,
            ITEM_PARTITION3 = 26,
            ITEM_ADVANCED3 = 27,
            ITEM_POWEROFF3 = 28,
            ITEM_REBOOT_RECOVERY3 = 29,
            ITEM_REBOOT_BOOTLOADER3 = 30,
            ITEM_APPLY_SDCARD4 = 31,
            ITEM_APPLY_CACHE4 = 32,
            ITEM_WIPE_DATA4 = 33,
            ITEM_WIPE_CACHE4 = 34,
            ITEM_NANDROID4 = 35,
            ITEM_PARTITION4 = 36,
            ITEM_ADVANCED4 = 37,
            ITEM_POWEROFF4 = 38,
            ITEM_REBOOT_RECOVERY4 = 39,
            ITEM_REBOOT_BOOTLOADER4 = 40,
            ITEM_APPLY_SDCARD5 = 41,
            ITEM_APPLY_CACHE5 = 42,
            ITEM_WIPE_DATA5 = 43,
            ITEM_WIPE_CACHE5 = 44,
            ITEM_NANDROID5 = 45,
            ITEM_PARTITION5 = 46,
            ITEM_ADVANCED5 = 47,
            ITEM_POWEROFF5 = 48,
            ITEM_REBOOT_RECOVERY5 = 49,
            ITEM_REBOOT_BOOTLOADER5 = 50,

                 
