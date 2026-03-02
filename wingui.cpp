#include "wingui.hpp"

namespace WinGui {
    static WinGuiContext *GWinGui = nullptr;

    WinGuiContext* CreateContext(ImFont* icon_font, ImFont* text_font) {
        auto context = new WinGuiContext();
        context->Typography.IconFont = icon_font;
        context->Typography.TextFont = text_font;

        return context;
    }

    void DestroyContext(WinGuiContext* context) {
        delete context;
    }

    WinGuiContext* GetCurrentContext() {
        return GWinGui;
    }

    void SetCurrentContext(WinGuiContext* ctx) {
        GWinGui = ctx;
    }

#if 0
void PushButtonColors(ButtonStyle style, Theme theme) {
    switch(style){
    case Destructive:
        ImGui::PushStyleColor(ImGuiCol_Button, IM_COL32(204, 14, 14, 255));
        ImGui::PushStyleColor(ImGuiCol_ButtonHovered, IM_COL32(232, 17, 35, 255));
        ImGui::PushStyleColor(ImGuiCol_ButtonActive, IM_COL32(241, 91, 91, 255));
        break;
    case Primary:
        if(theme == Theme::Dark){
            ImGui::PushStyleColor(ImGuiCol_Button, IM_COL32(76, 194, 255, 255));
            ImGui::PushStyleColor(ImGuiCol_ButtonHovered, IM_COL32(73, 179, 234, 255));
            ImGui::PushStyleColor(ImGuiCol_ButtonActive, IM_COL32(70, 165, 214, 255));
        } else {
            ImGui::PushStyleColor(ImGuiCol_Button, IM_COL32(0, 103, 192, 255));
            ImGui::PushStyleColor(ImGuiCol_ButtonHovered, IM_COL32(26, 118, 198, 255));
            ImGui::PushStyleColor(ImGuiCol_ButtonActive, IM_COL32(51, 133, 204, 255));
        }
        break;
    case Secondary:
        ImGui::PushStyleColor(ImGuiCol_Button, IM_COL32(255, 255, 255, 0));
        ImGui::PushStyleColor(ImGuiCol_ButtonHovered, IM_COL32(255, 255, 255, 40));
        ImGui::PushStyleColor(ImGuiCol_ButtonActive, IM_COL32(255, 255, 255, 60));
        break;
    }
}
#endif

void SetButtonColors(WinGuiStyle* style, WinGuiButton_ btn, ImU32 rest, ImU32 hover, ImU32 pressed, ImU32 disabled, ImU32 outline, ImU32 text) {
		style->ButtonStyles[btn][WinGuiButtonState_Rest].Color = rest;
		style->ButtonStyles[btn][WinGuiButtonState_Hover].Color = hover;
		style->ButtonStyles[btn][WinGuiButtonState_Pressed].Color = pressed;
		style->ButtonStyles[btn][WinGuiButtonState_Disabled].Color = disabled;
		
		for (int i = 0; i < WinGuiButtonState_COUNT; ++i) {
			style->ButtonStyles[btn][i].OutlineColor = outline;
			style->ButtonStyles[btn][i].ContentColor = text;
		}
	}

	void StyleColorsDark(WinGuiStyle* style) {
		IM_ASSERT(style);

		SetButtonColors(
			style,
			WinGuiButton_Accent,
			IM_COL32(76, 194, 255, 255),
			IM_COL32(73, 179, 234, 255),
			IM_COL32(70, 165, 214, 255),
			IM_COL32(255, 255, 255, 40),
			IM_COL32(255, 255, 255, 30),
			IM_COL32(0, 0, 0, 255)
		);
		
		SetButtonColors(
			style,
			WinGuiButton_Standard,
			IM_COL32(255, 255, 255, 15),
			IM_COL32(255, 255, 255, 22),
			IM_COL32(255, 255, 255, 8),
			IM_COL32(255, 255, 255, 40),
			IM_COL32(255, 255, 255, 20),
			IM_COL32(255, 255, 255, 255)
		);
		
		SetButtonColors(
			style,
			WinGuiButton_Subtle,
			IM_COL32(0, 0, 0, 0),
			IM_COL32(255, 255, 255, 15),
			IM_COL32(255, 255, 255, 8),
			IM_COL32(0, 0, 0, 0),
			IM_COL32(0, 0, 0, 0),
			IM_COL32(255, 255, 255, 255)
		);
		
		SetButtonColors(
			style,
			WinGuiButton_Destructive,
			IM_COL32(204, 14, 14, 255),
			IM_COL32(232, 17, 35, 255),
			IM_COL32(241, 91, 91, 255),
			IM_COL32(255, 255, 255, 40),
			IM_COL32(255, 255, 255, 50),
			IM_COL32(255, 255, 255, 255)
		);
	}

	void StyleColorsLight(WinGuiStyle* style) {
		IM_ASSERT(style);

		SetButtonColors(
			style,
			WinGuiButton_Accent,
			IM_COL32(0, 103, 192, 255),
			IM_COL32(26, 118, 198, 255),
			IM_COL32(51, 133, 204, 255),
			IM_COL32(0, 0, 0, 55),
			IM_COL32(0, 0, 0, 30),
			IM_COL32(255, 255, 255, 255)
		);
		
		SetButtonColors(
			style,
			WinGuiButton_Standard,
			IM_COL32(253, 253, 253, 255),
			IM_COL32(245, 245, 245, 255),
			IM_COL32(235, 235, 235, 255),
			IM_COL32(0, 0, 0, 55),
			IM_COL32(0, 0, 0, 20),
			IM_COL32(0, 0, 0, 255)
		);
		
		SetButtonColors(
			style,
			WinGuiButton_Subtle,
			IM_COL32(0, 0, 0, 0),
			IM_COL32(0, 0, 0, 10),
			IM_COL32(0, 0, 0, 18),
			IM_COL32(0, 0, 0, 0),
			IM_COL32(0, 0, 0, 0),
			IM_COL32(0, 0, 0, 255)
		);
		
		SetButtonColors(
			style,
			WinGuiButton_Destructive,
			IM_COL32(196, 43, 28, 255),
			IM_COL32(177, 36, 21, 255),
			IM_COL32(153, 20, 10, 255),
			IM_COL32(0, 0, 0, 55),
			IM_COL32(0, 0, 0, 40),
			IM_COL32(255, 255, 255, 255)
		);
	}

	bool Button(const char* text, WinGuiButton_ button, ImFont *font, ImGuiButtonFlags flags) {
		auto* ctx = GetCurrentContext();
		IM_ASSERT(ctx && "Context is nullptr");

		auto& button_states = ctx->Style.ButtonStyles[button];

		ImGui::PushStyleColor(ImGuiCol_Button,        button_states[WinGuiButtonState_Rest].Color);
		ImGui::PushStyleColor(ImGuiCol_ButtonHovered, button_states[WinGuiButtonState_Hover].Color);
		ImGui::PushStyleColor(ImGuiCol_ButtonActive,  button_states[WinGuiButtonState_Pressed].Color);
		ImGui::PushStyleColor(ImGuiCol_Text,          button_states[WinGuiButtonState_Rest].ContentColor);
		ImGui::PushStyleColor(ImGuiCol_Border,        button_states[WinGuiButtonState_Rest].OutlineColor);

		ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, {12.f, 10.f});
		ImGui::PushStyleVar(ImGuiStyleVar_FrameBorderSize, 1.0f); // Включаем отрисовку аутлайна

		ImGui::PushFont(font);

		bool ret = ImGui::Button(text);

		ImGui::PopFont(); 

		ImGui::PopStyleVar(2);
		ImGui::PopStyleColor(5);

		return ret;
	}

	bool IconButton(const char* text, WinGuiButton_ button, ImGuiButtonFlags flags) {
		auto* ctx = GetCurrentContext();
		IM_ASSERT(ctx && "Context is nullptr");
		return Button(text, button, ctx->Typography.IconFont, flags);
	}

	bool TextButton(const char* text, WinGuiButton_ button, ImGuiButtonFlags flags) {
		auto* ctx = GetCurrentContext();
		IM_ASSERT(ctx && "Context is nullptr");
		return Button(text, button, ctx->Typography.TextFont, flags);
	}

}