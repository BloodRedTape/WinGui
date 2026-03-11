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
   float OutlineSize = 1.f;
   //ImU32 ShadowColor = WIN_DEBUG_NULL_COLOR;
   ImU32 ContentColor = WIN_DEBUG_NULL_COLOR;
   float Rounding = 3.f;
};

struct WinGuiButtonLayout {
    float IconTextSpacing = 10.f;
    ImVec2 ContentPadding = {12.f, 10.f};
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
   float OutlineSize = 1.f;
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

enum WinGuiSelectable_ {
    WinGuiSelectable_Selected,
    WinGuiSelectable_Unselected,
    WinGuiSelectable_COUNT
};

struct WinGuiSelectableStyle {
   ImU32 Accent = WIN_DEBUG_NULL_COLOR;
};

struct WinGuiSelectableLayout {
    ImVec2 ContentPadding = {12.f, 8.f};
};

struct WinGuiStyle {
    WinGuiButtonStyle ButtonStyles[WinGuiButton_COUNT][WinGuiWidgetState_COUNT];
    WinGuiButtonStyle CheckboxStyles[WinGuiCheckbox_COUNT][WinGuiWidgetState_COUNT];
    WinGuiButtonStyle RadioButtonStyles[WinGuiRadioButton_COUNT][WinGuiWidgetState_COUNT];
    WinGuiSelectableStyle SelectableStyle;
    WinGuiLayerStyle LayerStyles[WinGuiLayer_COUNT];
};

struct WinGuiPopupLayout {
    ImVec2 ContentPadding = {6.f, 6.f};
};

struct WinGuiLayout {
    WinGuiButtonLayout ButtonLayout;
    WinGuiPopupLayout PopupLayout;
    WinGuiSelectableLayout SelectableLayout;
};

struct WinGuiContext {
    WinGuiFontAtlas Typography;
    WinGuiStyle Style;
    WinGuiLayout Layout;
};

enum WinGuiPopup_ {
    WinGuiPopup_Below,
    WinGuiPopup_Over,
    WinGuiPopup_Mouse
};

struct WinIcon {
    char Utf8Data[5] = {0};

    WinIcon() = default;

    WinIcon(std::uint32_t code);

    const char *CStr()const;

    operator const char*() const;

    bool IsValid()const;

    operator bool()const;
};

namespace WinGui {
        
    WinGuiContext *CreateContext(ImFont *icon_font, ImFont *text_font);
    void DestroyContext(WinGuiContext *context);
    WinGuiContext *GetCurrentContext();
    void SetCurrentContext(WinGuiContext *ctx);

    void StyleColorsDark(WinGuiStyle *style);
    void StyleColorsLight(WinGuiStyle *style);

    WinGuiStyle &GetStyle();
    WinGuiFontAtlas &GetTypography();
    WinGuiLayout &GetLayout();

    bool Begin(const char* name, bool* p_open = nullptr, WinGuiLayer_ layer = WinGuiLayer_Content, ImGuiWindowFlags flags = 0);
    void End();

    bool BeginChild(const char* name, WinGuiLayer_ layer = WinGuiLayer_Content , const ImVec2& size = ImVec2(0, 0), ImGuiChildFlags child_flags = 0, ImGuiWindowFlags window_flags = 0);
    void EndChild();

    void BeginFullWindow(const char *name, ImVec2 size, ImVec2 pos, ImGuiWindowFlags flags = 0);
    void EndFullWindow();

    void Icon(WinIcon icon);

    void IconText(WinIcon icon, const char *text, int spacing = 0);

    ImVec2 CalcIconTextSize(WinIcon icon, const char *text, int spacing);

    bool IconButton(WinIcon icon, WinGuiButton_ button, ImGuiButtonFlags flags = 0);

    inline bool AccentIconButton(WinIcon icon, ImGuiButtonFlags flags = 0) {
        return IconButton(icon, WinGuiButton_Accent, flags);
    }

    inline bool StandardIconButton(WinIcon icon, ImGuiButtonFlags flags = 0) {
        return IconButton(icon, WinGuiButton_Standard, flags);
    }

    inline bool SubtleIconButton(WinIcon icon, ImGuiButtonFlags flags = 0) {
        return IconButton(icon, WinGuiButton_Subtle, flags);
    }
    inline bool DestructiveIconButton(WinIcon icon, ImGuiButtonFlags flags = 0) {
        return IconButton(icon, WinGuiButton_Destructive, flags);
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

    bool IconTextButton(WinIcon leading, const char* text, WinIcon trailing, WinGuiButton_ button, ImGuiButtonFlags flags = 0);

    inline bool AccentIconTextButton(WinIcon icon, const char* text, ImGuiButtonFlags flags = 0) {
        return IconTextButton(icon, text, {},  WinGuiButton_Accent, flags);
    }

    inline bool StandardIconTextButton(WinIcon icon, const char* text, ImGuiButtonFlags flags = 0) {
        return IconTextButton(icon, text, {}, WinGuiButton_Standard, flags);
    }

    inline bool SubtleIconTextButton(WinIcon icon, const char* text, ImGuiButtonFlags flags = 0) {
        return IconTextButton(icon, text, {}, WinGuiButton_Subtle, flags);
    }
    inline bool DestructiveIconTextButton(WinIcon icon, const char* text, ImGuiButtonFlags flags = 0) {
        return IconTextButton(icon, text, {}, WinGuiButton_Destructive, flags);
    }

    std::tuple<bool, bool, bool> WindowControlButtons(WinIcon minimize_icon, WinIcon maximize_icon, WinIcon close_icon);

    void OpenPopup(const char *name);

    bool BeginPopup(const char *name, WinGuiPopup_ type = WinGuiPopup_Mouse);

    void EndPopup();

    void SpacingX(int spacing);

    bool Checkbox(const char *name, bool *v);

    bool RadioButton(const char *name, bool active);

    bool Selectable(const char *text, bool selected);

    bool Selectable(const char *text, bool *selected);

    bool BeginCombo(const char *name, const char *preview, WinIcon icon, WinGuiButton_ style = WinGuiButton_Standard, WinGuiPopup_ popup_style = WinGuiPopup_Below);

    void EndCombo();

}//namespace ImGui::
