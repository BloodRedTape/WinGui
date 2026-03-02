#pragma once

#include <imgui.h>
#include <tuple>

struct WinGuiFontAtlas {
    ImFont *IconFont = nullptr;
    ImFont *TextFont = nullptr;
};

#define WIN_DEBUG_NULL_COLOR IM_COL32(255, 0, 255, 255)

struct WinGuiButtonStyle {
   ImU32 Color = WIN_DEBUG_NULL_COLOR;
   ImU32 OutlineColor = WIN_DEBUG_NULL_COLOR;
   //ImU32 ShadowColor = WIN_DEBUG_NULL_COLOR;
   ImU32 ContentColor = WIN_DEBUG_NULL_COLOR;
};

enum WinGuiButton_ {
    WinGuiButton_Accent,
    WinGuiButton_Standard,
    WinGuiButton_Subtle,
    WinGuiButton_Destructive,
    WinGuiButton_COUNT
};

enum WinGuiButtonState_ {
    WinGuiButtonState_Rest,
    WinGuiButtonState_Hover,
    WinGuiButtonState_Pressed,
    WinGuiButtonState_Disabled,
    //WinGuiButtonState_Focus,
    WinGuiButtonState_COUNT,
};

struct WinGuiLayerStyle {
   ImU32 Color = WIN_DEBUG_NULL_COLOR;
   ImU32 OutlineColor = WIN_DEBUG_NULL_COLOR;
   ImU32 ShadowColor = WIN_DEBUG_NULL_COLOR;
};

enum WinGuiLayer_ {
    WinGuiLayer_Base,
    WinGuiLayer_Content,
    WinGuiLayer_COUNT,
};

struct WinGuiStyle {
    WinGuiButtonStyle ButtonStyles[WinGuiButton_COUNT][WinGuiButtonState_COUNT];
    WinGuiLayerStyle LayerStyles[WinGuiLayer_COUNT];
};

struct WinGuiContext {
    WinGuiFontAtlas Typography;
    WinGuiStyle Style;
};

namespace WinGui {
        
    WinGuiContext *CreateContext(ImFont *icon_font, ImFont *text_font);
    void DestroyContext(WinGuiContext *context);
    WinGuiContext *GetCurrentContext();
    void SetCurrentContext(WinGuiContext *ctx);

    void StyleColorsDark(WinGuiStyle *style);
    void StyleColorsLight(WinGuiStyle *style);

    bool Begin(const char* name, bool* p_open = nullptr, WinGuiLayer_ layer = WinGuiLayer_Content, ImGuiWindowFlags flags = 0);
    void End();

    bool BeginChild(const char* name, WinGuiLayer_ layer = WinGuiLayer_Content , const ImVec2& size = ImVec2(0, 0), ImGuiChildFlags child_flags = 0, ImGuiWindowFlags window_flags = 0);
    void EndChild();

    void BeginFullWindow(const char *name, ImVec2 size, ImVec2 pos, ImGuiWindowFlags flags = 0);
    void EndFullWindow();

    bool IconButton(const char* text, WinGuiButton_ button, ImGuiButtonFlags flags = 0);

    inline bool AccentIconButton(const char* text, ImGuiButtonFlags flags = 0) {
        return IconButton(text, WinGuiButton_Accent, flags);
    }

    inline bool StandardIconButton(const char* text, ImGuiButtonFlags flags = 0) {
        return IconButton(text, WinGuiButton_Standard, flags);
    }

    inline bool SubtleIconButton(const char* text, ImGuiButtonFlags flags = 0) {
        return IconButton(text, WinGuiButton_Subtle, flags);
    }
    inline bool DestructiveIconButton(const char* text, ImGuiButtonFlags flags = 0) {
        return IconButton(text, WinGuiButton_Destructive, flags);
    }

    bool TextButton(const char* text, WinGuiButton_ button, ImGuiButtonFlags flags = 0);

    inline bool AccentTextButton(const char* text, ImGuiButtonFlags flags = 0) {
        return TextButton(text, WinGuiButton_Accent, flags);
    }

    inline bool StandardTextButton(const char* text, ImGuiButtonFlags flags = 0) {
        return TextButton(text, WinGuiButton_Standard, flags);
    }

    inline bool SubtleTextButton(const char* text, ImGuiButtonFlags flags = 0) {
        return TextButton(text, WinGuiButton_Subtle, flags);
    }
    inline bool DestructiveTextButton(const char* text, ImGuiButtonFlags flags = 0) {
        return TextButton(text, WinGuiButton_Destructive, flags);
    }

    void Icon(const char *icon);

    std::tuple<bool, bool, bool> WindowControlButtons(const char *minimize_icon, const char *maximize_icon, const char *close_icon);

}//namespace ImGui::


namespace WinIcon {
    static const char *Wifi = "\xEE\x9C\x81";
    static const char *Copy = "\xEE\xA3\x88";
    static const char *Delete = "\xEE\x9D\x8D";
    static const char *More = "\xEE\x9C\x92";
    static const char *Forward = "\xEE\x9C\xAA";
    static const char *Back = "\xEE\x9C\xAB";

    static const char *Picture = "\xEE\xA2\xB9";
    static const char *Save = "\xEE\x9D\x8E";
    static const char *Info = "\xEE\xA5\x86";

    static const char *ChromeClose = "\xEE\xA2\xBB";
    static const char *ChromeMinimize = "\xEE\xA4\xA1";
    static const char *ChromeMaximize = "\xEE\xA4\xA2";
    static const char *ChromeRestore = "\xEE\xA4\xA3";
}//namespace Icon::
