#pragma once

#define IMGUI_DEFINE_MATH_OPERATORS
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

enum WinGuiWidgetState {
    WinGuiWidgetState_Rest,
    WinGuiWidgetState_Hover,
    WinGuiWidgetState_Pressed,
    WinGuiWidgetState_Disabled,
    //WinGuiWidgetState_Focus,
    WinGuiWidgetState_COUNT,
};

struct WinGuiLayerStyle {
   ImU32 Color = WIN_DEBUG_NULL_COLOR;
   ImU32 OutlineColor = WIN_DEBUG_NULL_COLOR;
   ImU32 ShadowColor = WIN_DEBUG_NULL_COLOR;
};

enum WinGuiLayer_ {
    WinGuiLayer_Base,
    WinGuiLayer_Content,
    WinGuiLayer_COUNT
};

enum WinGuiCheckbox_ {
    WinGuiCheckbox_Checked,
    WinGuiCheckbox_Unchecked,
    WinGuiCheckbox_Undetermined,
    WinGuiCheckbox_COUNT
};

enum WinGuiRadioButton_ {
    WinGuiRadioButton_Active,
    WinGuiRadioButton_Unactive,
    WinGuiRadioButton_COUNT
};

struct WinGuiStyle {
    WinGuiButtonStyle ButtonStyles[WinGuiButton_COUNT][WinGuiWidgetState_COUNT];
    WinGuiButtonStyle CheckboxStyles[WinGuiCheckbox_COUNT][WinGuiWidgetState_COUNT];
    WinGuiButtonStyle RadioButtonStyles[WinGuiRadioButton_COUNT][WinGuiWidgetState_COUNT];
    WinGuiLayerStyle LayerStyles[WinGuiLayer_COUNT];
};

struct WinGuiContext {
    WinGuiFontAtlas Typography;
    WinGuiStyle Style;
};

enum WinGuiPopup_ {
    WinGuiPopup_Below,
    WinGuiPopup_Over,
    WinGuiPopup_Mouse
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

    void Icon(const char *icon);

    void IconText(const char *icon, const char *text, int spacing = 0);

    ImVec2 CalcIconTextSize(const char *icon, const char *text, int spacing);

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

    bool IconTextButton(const char *icon, const char* text, WinGuiButton_ button, ImGuiButtonFlags flags = 0);

    inline bool AccentIconTextButton(const char *icon, const char* text, ImGuiButtonFlags flags = 0) {
        return IconTextButton(icon, text, WinGuiButton_Accent, flags);
    }

    inline bool StandardIconTextButton(const char *icon, const char* text, ImGuiButtonFlags flags = 0) {
        return IconTextButton(icon, text, WinGuiButton_Standard, flags);
    }

    inline bool SubtleIconTextButton(const char *icon, const char* text, ImGuiButtonFlags flags = 0) {
        return IconTextButton(icon, text, WinGuiButton_Subtle, flags);
    }
    inline bool DestructiveIconTextButton(const char *icon, const char* text, ImGuiButtonFlags flags = 0) {
        return IconTextButton(icon, text, WinGuiButton_Destructive, flags);
    }

    std::tuple<bool, bool, bool> WindowControlButtons(const char *minimize_icon, const char *maximize_icon, const char *close_icon);

    void OpenPopup(const char *name);

    bool BeginPopup(const char *name, WinGuiPopup_ type = WinGuiPopup_Mouse);

    void EndPopup();

    void SpacingX(int spacing);

    void Checkbox(const char *name, bool *v);

    void RadioButton(const char *name, bool active);

}//namespace ImGui::


namespace WinIcon {
    static const char *Wifi = "\xEE\x9C\x81";
    static const char *Copy = "\xEE\xA3\x88";
    static const char *Delete = "\xEE\x9D\x8D";
    static const char *More = "\xEE\x9C\x92";
    static const char *Forward = "\xEE\x9C\xAA";
    static const char *Back = "\xEE\x9C\xAB";
    static const char *BrowsePhotos = "\xEE\x9F\x85";
    static const char *Sync = "\xEE\xA2\x95";
    static const char *Remove = "\xEE\x9C\xB8";
    static const char *Stop = "\xEE\x9C\x9A";
    static const char *Cancel = "\xEE\x9C\x91";

    static const char *Picture = "\xEE\xA2\xB9";
    static const char *Save = "\xEE\x9D\x8E";
    static const char *Info = "\xEE\xA5\x86";

    static const char *ChromeClose = "\xEE\xA2\xBB";
    static const char *ChromeMinimize = "\xEE\xA4\xA1";
    static const char *ChromeMaximize = "\xEE\xA4\xA2";
    static const char *ChromeRestore = "\xEE\xA4\xA3";
}//namespace Icon::
