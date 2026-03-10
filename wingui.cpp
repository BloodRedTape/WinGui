#include "wingui.hpp"
#include "imgui_internal.h"

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

	void SetButtonColors(WinGuiStyle* style, WinGuiButton_ btn, ImU32 rest, ImU32 hover, ImU32 pressed, ImU32 disabled, ImU32 outline, ImU32 text) {
		style->ButtonStyles[btn][WinGuiWidgetState_Rest].Color = rest;
		style->ButtonStyles[btn][WinGuiWidgetState_Hover].Color = hover;
		style->ButtonStyles[btn][WinGuiWidgetState_Pressed].Color = pressed;
		style->ButtonStyles[btn][WinGuiWidgetState_Disabled].Color = disabled;
		
		for (int i = 0; i < WinGuiWidgetState_COUNT; ++i) {
			style->ButtonStyles[btn][i].OutlineColor = outline;
			style->ButtonStyles[btn][i].ContentColor = text;
		}
	}

	void PropagateCheckboxColors(WinGuiStyle* style) {
		IM_ASSERT(style);
		
		style->CheckboxStyles[WinGuiCheckbox_Checked][WinGuiWidgetState_Rest].Color = style->ButtonStyles[WinGuiButton_Accent][WinGuiWidgetState_Rest].Color;
		style->CheckboxStyles[WinGuiCheckbox_Checked][WinGuiWidgetState_Rest].ContentColor = style->ButtonStyles[WinGuiButton_Accent][WinGuiWidgetState_Rest].ContentColor;
		style->CheckboxStyles[WinGuiCheckbox_Checked][WinGuiWidgetState_Rest].OutlineColor = style->ButtonStyles[WinGuiButton_Accent][WinGuiWidgetState_Rest].OutlineColor;

		style->CheckboxStyles[WinGuiCheckbox_Checked][WinGuiWidgetState_Hover].Color = style->ButtonStyles[WinGuiButton_Accent][WinGuiWidgetState_Hover].Color;
		style->CheckboxStyles[WinGuiCheckbox_Checked][WinGuiWidgetState_Hover].ContentColor = style->ButtonStyles[WinGuiButton_Accent][WinGuiWidgetState_Hover].ContentColor;
		style->CheckboxStyles[WinGuiCheckbox_Checked][WinGuiWidgetState_Hover].OutlineColor = style->ButtonStyles[WinGuiButton_Accent][WinGuiWidgetState_Hover].OutlineColor;

		style->CheckboxStyles[WinGuiCheckbox_Checked][WinGuiWidgetState_Pressed].Color = style->ButtonStyles[WinGuiButton_Accent][WinGuiWidgetState_Pressed].Color;
		style->CheckboxStyles[WinGuiCheckbox_Checked][WinGuiWidgetState_Pressed].ContentColor = style->ButtonStyles[WinGuiButton_Accent][WinGuiWidgetState_Pressed].ContentColor;
		style->CheckboxStyles[WinGuiCheckbox_Checked][WinGuiWidgetState_Pressed].OutlineColor = style->ButtonStyles[WinGuiButton_Accent][WinGuiWidgetState_Pressed].OutlineColor;

		style->CheckboxStyles[WinGuiCheckbox_Checked][WinGuiWidgetState_Disabled].Color = style->ButtonStyles[WinGuiButton_Accent][WinGuiWidgetState_Disabled].Color;
		style->CheckboxStyles[WinGuiCheckbox_Checked][WinGuiWidgetState_Disabled].ContentColor = style->ButtonStyles[WinGuiButton_Accent][WinGuiWidgetState_Disabled].ContentColor;
		style->CheckboxStyles[WinGuiCheckbox_Checked][WinGuiWidgetState_Disabled].OutlineColor = style->ButtonStyles[WinGuiButton_Accent][WinGuiWidgetState_Disabled].OutlineColor;



		style->CheckboxStyles[WinGuiCheckbox_Undetermined][WinGuiWidgetState_Rest].Color = style->ButtonStyles[WinGuiButton_Accent][WinGuiWidgetState_Rest].Color;
		style->CheckboxStyles[WinGuiCheckbox_Undetermined][WinGuiWidgetState_Rest].ContentColor = style->ButtonStyles[WinGuiButton_Accent][WinGuiWidgetState_Rest].ContentColor;
		style->CheckboxStyles[WinGuiCheckbox_Undetermined][WinGuiWidgetState_Rest].OutlineColor = style->ButtonStyles[WinGuiButton_Accent][WinGuiWidgetState_Rest].OutlineColor;

		style->CheckboxStyles[WinGuiCheckbox_Undetermined][WinGuiWidgetState_Hover].Color = style->ButtonStyles[WinGuiButton_Accent][WinGuiWidgetState_Hover].Color;
		style->CheckboxStyles[WinGuiCheckbox_Undetermined][WinGuiWidgetState_Hover].ContentColor = style->ButtonStyles[WinGuiButton_Accent][WinGuiWidgetState_Hover].ContentColor;
		style->CheckboxStyles[WinGuiCheckbox_Undetermined][WinGuiWidgetState_Hover].OutlineColor = style->ButtonStyles[WinGuiButton_Accent][WinGuiWidgetState_Hover].OutlineColor;

		style->CheckboxStyles[WinGuiCheckbox_Undetermined][WinGuiWidgetState_Pressed].Color = style->ButtonStyles[WinGuiButton_Accent][WinGuiWidgetState_Pressed].Color;
		style->CheckboxStyles[WinGuiCheckbox_Undetermined][WinGuiWidgetState_Pressed].ContentColor = style->ButtonStyles[WinGuiButton_Accent][WinGuiWidgetState_Pressed].ContentColor;
		style->CheckboxStyles[WinGuiCheckbox_Undetermined][WinGuiWidgetState_Pressed].OutlineColor = style->ButtonStyles[WinGuiButton_Accent][WinGuiWidgetState_Pressed].OutlineColor;

		style->CheckboxStyles[WinGuiCheckbox_Undetermined][WinGuiWidgetState_Disabled].Color = style->ButtonStyles[WinGuiButton_Accent][WinGuiWidgetState_Disabled].Color;
		style->CheckboxStyles[WinGuiCheckbox_Undetermined][WinGuiWidgetState_Disabled].ContentColor = style->ButtonStyles[WinGuiButton_Accent][WinGuiWidgetState_Disabled].ContentColor;
		style->CheckboxStyles[WinGuiCheckbox_Undetermined][WinGuiWidgetState_Disabled].OutlineColor = style->ButtonStyles[WinGuiButton_Accent][WinGuiWidgetState_Disabled].OutlineColor;



		style->CheckboxStyles[WinGuiCheckbox_Unchecked][WinGuiWidgetState_Rest].Color = style->ButtonStyles[WinGuiButton_Standard][WinGuiWidgetState_Rest].Color;
		style->CheckboxStyles[WinGuiCheckbox_Unchecked][WinGuiWidgetState_Rest].ContentColor = style->ButtonStyles[WinGuiButton_Standard][WinGuiWidgetState_Rest].ContentColor;
		style->CheckboxStyles[WinGuiCheckbox_Unchecked][WinGuiWidgetState_Rest].OutlineColor = style->ButtonStyles[WinGuiButton_Standard][WinGuiWidgetState_Rest].OutlineColor;

		style->CheckboxStyles[WinGuiCheckbox_Unchecked][WinGuiWidgetState_Hover].Color = style->ButtonStyles[WinGuiButton_Standard][WinGuiWidgetState_Hover].Color;
		style->CheckboxStyles[WinGuiCheckbox_Unchecked][WinGuiWidgetState_Hover].ContentColor = style->ButtonStyles[WinGuiButton_Standard][WinGuiWidgetState_Hover].ContentColor;
		style->CheckboxStyles[WinGuiCheckbox_Unchecked][WinGuiWidgetState_Hover].OutlineColor = style->ButtonStyles[WinGuiButton_Standard][WinGuiWidgetState_Hover].OutlineColor;

		style->CheckboxStyles[WinGuiCheckbox_Unchecked][WinGuiWidgetState_Pressed].Color = style->ButtonStyles[WinGuiButton_Standard][WinGuiWidgetState_Pressed].Color;
		style->CheckboxStyles[WinGuiCheckbox_Unchecked][WinGuiWidgetState_Pressed].ContentColor = style->ButtonStyles[WinGuiButton_Standard][WinGuiWidgetState_Pressed].ContentColor;
		style->CheckboxStyles[WinGuiCheckbox_Unchecked][WinGuiWidgetState_Pressed].OutlineColor = style->ButtonStyles[WinGuiButton_Standard][WinGuiWidgetState_Pressed].OutlineColor;

		style->CheckboxStyles[WinGuiCheckbox_Unchecked][WinGuiWidgetState_Disabled].Color = style->ButtonStyles[WinGuiButton_Standard][WinGuiWidgetState_Disabled].Color;
		style->CheckboxStyles[WinGuiCheckbox_Unchecked][WinGuiWidgetState_Disabled].ContentColor = style->ButtonStyles[WinGuiButton_Standard][WinGuiWidgetState_Disabled].ContentColor;
		style->CheckboxStyles[WinGuiCheckbox_Unchecked][WinGuiWidgetState_Disabled].OutlineColor = style->ButtonStyles[WinGuiButton_Standard][WinGuiWidgetState_Disabled].OutlineColor;
	}

	void PropagateRadioButtonColors(WinGuiStyle* style) {
		IM_ASSERT(style);
		
		style->RadioButtonStyles[WinGuiRadioButton_Active][WinGuiWidgetState_Rest].Color = style->ButtonStyles[WinGuiButton_Accent][WinGuiWidgetState_Rest].Color;
		style->RadioButtonStyles[WinGuiRadioButton_Active][WinGuiWidgetState_Rest].ContentColor = style->ButtonStyles[WinGuiButton_Accent][WinGuiWidgetState_Rest].ContentColor;
		style->RadioButtonStyles[WinGuiRadioButton_Active][WinGuiWidgetState_Rest].OutlineColor = style->ButtonStyles[WinGuiButton_Accent][WinGuiWidgetState_Rest].OutlineColor;

		style->RadioButtonStyles[WinGuiRadioButton_Active][WinGuiWidgetState_Hover].Color = style->ButtonStyles[WinGuiButton_Accent][WinGuiWidgetState_Hover].Color;
		style->RadioButtonStyles[WinGuiRadioButton_Active][WinGuiWidgetState_Hover].ContentColor = style->ButtonStyles[WinGuiButton_Accent][WinGuiWidgetState_Hover].ContentColor;
		style->RadioButtonStyles[WinGuiRadioButton_Active][WinGuiWidgetState_Hover].OutlineColor = style->ButtonStyles[WinGuiButton_Accent][WinGuiWidgetState_Hover].OutlineColor;

		style->RadioButtonStyles[WinGuiRadioButton_Active][WinGuiWidgetState_Pressed].Color = style->ButtonStyles[WinGuiButton_Accent][WinGuiWidgetState_Pressed].Color;
		style->RadioButtonStyles[WinGuiRadioButton_Active][WinGuiWidgetState_Pressed].ContentColor = style->ButtonStyles[WinGuiButton_Accent][WinGuiWidgetState_Pressed].ContentColor;
		style->RadioButtonStyles[WinGuiRadioButton_Active][WinGuiWidgetState_Pressed].OutlineColor = style->ButtonStyles[WinGuiButton_Accent][WinGuiWidgetState_Pressed].OutlineColor;

		style->RadioButtonStyles[WinGuiRadioButton_Active][WinGuiWidgetState_Disabled].Color = style->ButtonStyles[WinGuiButton_Accent][WinGuiWidgetState_Disabled].Color;
		style->RadioButtonStyles[WinGuiRadioButton_Active][WinGuiWidgetState_Disabled].ContentColor = style->ButtonStyles[WinGuiButton_Accent][WinGuiWidgetState_Disabled].ContentColor;
		style->RadioButtonStyles[WinGuiRadioButton_Active][WinGuiWidgetState_Disabled].OutlineColor = style->ButtonStyles[WinGuiButton_Accent][WinGuiWidgetState_Disabled].OutlineColor;


		style->RadioButtonStyles[WinGuiRadioButton_Unactive][WinGuiWidgetState_Rest].Color = style->ButtonStyles[WinGuiButton_Standard][WinGuiWidgetState_Rest].Color;
		style->RadioButtonStyles[WinGuiRadioButton_Unactive][WinGuiWidgetState_Rest].ContentColor = style->ButtonStyles[WinGuiButton_Standard][WinGuiWidgetState_Rest].ContentColor;
		style->RadioButtonStyles[WinGuiRadioButton_Unactive][WinGuiWidgetState_Rest].OutlineColor = style->ButtonStyles[WinGuiButton_Standard][WinGuiWidgetState_Rest].OutlineColor;

		style->RadioButtonStyles[WinGuiRadioButton_Unactive][WinGuiWidgetState_Hover].Color = style->ButtonStyles[WinGuiButton_Standard][WinGuiWidgetState_Hover].Color;
		style->RadioButtonStyles[WinGuiRadioButton_Unactive][WinGuiWidgetState_Hover].ContentColor = style->ButtonStyles[WinGuiButton_Standard][WinGuiWidgetState_Hover].ContentColor;
		style->RadioButtonStyles[WinGuiRadioButton_Unactive][WinGuiWidgetState_Hover].OutlineColor = style->ButtonStyles[WinGuiButton_Standard][WinGuiWidgetState_Hover].OutlineColor;

		style->RadioButtonStyles[WinGuiRadioButton_Unactive][WinGuiWidgetState_Pressed].Color = style->ButtonStyles[WinGuiButton_Standard][WinGuiWidgetState_Pressed].Color;
		style->RadioButtonStyles[WinGuiRadioButton_Unactive][WinGuiWidgetState_Pressed].ContentColor = style->ButtonStyles[WinGuiButton_Standard][WinGuiWidgetState_Pressed].ContentColor;
		style->RadioButtonStyles[WinGuiRadioButton_Unactive][WinGuiWidgetState_Pressed].OutlineColor = style->ButtonStyles[WinGuiButton_Standard][WinGuiWidgetState_Pressed].OutlineColor;

		style->RadioButtonStyles[WinGuiRadioButton_Unactive][WinGuiWidgetState_Disabled].Color = style->ButtonStyles[WinGuiButton_Standard][WinGuiWidgetState_Disabled].Color;
		style->RadioButtonStyles[WinGuiRadioButton_Unactive][WinGuiWidgetState_Disabled].ContentColor = style->ButtonStyles[WinGuiButton_Standard][WinGuiWidgetState_Disabled].ContentColor;
		style->RadioButtonStyles[WinGuiRadioButton_Unactive][WinGuiWidgetState_Disabled].OutlineColor = style->ButtonStyles[WinGuiButton_Standard][WinGuiWidgetState_Disabled].OutlineColor;
	}

	void StyleColorsDark(WinGuiStyle* style) {
		IM_ASSERT(style);

		style->LayerStyles[WinGuiLayer_Base].Color        = IM_COL32(32, 32, 32, 255); 
		style->LayerStyles[WinGuiLayer_Base].OutlineColor = IM_COL32(0, 0, 0, 0);
		style->LayerStyles[WinGuiLayer_Base].ShadowColor  = IM_COL32(0, 0, 0, 0);

		style->LayerStyles[WinGuiLayer_Content].Color        = IM_COL32(45, 45, 45, 255);
		style->LayerStyles[WinGuiLayer_Content].OutlineColor = IM_COL32(64, 64, 64, 255);
		style->LayerStyles[WinGuiLayer_Content].ShadowColor  = IM_COL32(0, 0, 0, 130);

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

		PropagateCheckboxColors(style);
		PropagateRadioButtonColors(style);
	}

	void StyleColorsLight(WinGuiStyle* style) {
		IM_ASSERT(style);

		style->LayerStyles[WinGuiLayer_Base].Color        = IM_COL32(243, 243, 243, 255); 	
		style->LayerStyles[WinGuiLayer_Base].OutlineColor = IM_COL32(0, 0, 0, 0);
		style->LayerStyles[WinGuiLayer_Base].ShadowColor  = IM_COL32(0, 0, 0, 0);

		style->LayerStyles[WinGuiLayer_Content].Color        = IM_COL32(255, 255, 255, 255);
		style->LayerStyles[WinGuiLayer_Content].OutlineColor = IM_COL32(229, 229, 229, 255);
		style->LayerStyles[WinGuiLayer_Content].ShadowColor  = IM_COL32(0, 0, 0, 15);

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
			IM_COL32(230, 230, 230, 255),
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

		PropagateCheckboxColors(style);
		PropagateRadioButtonColors(style);
	}

	bool Begin(const char* name, bool* p_open, WinGuiLayer_ layer, ImGuiWindowFlags flags) {
		auto* ctx = GetCurrentContext();
		IM_ASSERT(ctx && "Context is nullptr");

		auto layer_style = ctx->Style.LayerStyles[layer];

		ImGui::PushStyleColor(ImGuiCol_WindowBg, layer_style.Color);
		ImGui::PushStyleColor(ImGuiCol_Border, layer_style.OutlineColor);
		ImGui::PushStyleColor(ImGuiCol_BorderShadow, layer_style.ShadowColor);
		bool ret = ImGui::Begin(name, p_open, flags);
		ImGui::PopStyleColor(3);
		return ret;
	}

	void End() {
		ImGui::End();
	}

	bool BeginChild(const char* name, WinGuiLayer_ layer, const ImVec2& size, ImGuiChildFlags child_flags, ImGuiWindowFlags window_flags) {
		auto* ctx = GetCurrentContext();
		IM_ASSERT(ctx && "Context is nullptr");

		auto layer_style = ctx->Style.LayerStyles[layer];

		ImGui::PushStyleColor(ImGuiCol_ChildBg, layer_style.Color);
		ImGui::PushStyleColor(ImGuiCol_Border, layer_style.OutlineColor);
		ImGui::PushStyleColor(ImGuiCol_BorderShadow, layer_style.ShadowColor);
		auto ret = ImGui::BeginChild(name, size, child_flags, window_flags);
		ImGui::PopStyleColor(3);
		return ret;
	}

	void EndChild() {
		ImGui::EndChild();
	}

	void BeginFullWindow(const char* name, ImVec2 size, ImVec2 pos, ImGuiWindowFlags flags) {
		auto* ctx = GetCurrentContext();
		IM_ASSERT(ctx && "Context is nullptr");

		ImGui::SetNextWindowSize(size);
		ImGui::SetNextWindowPos(pos);

		flags |= ImGuiWindowFlags_NoTitleBar;
		flags |= ImGuiWindowFlags_NoResize;
		flags |= ImGuiWindowFlags_NoBringToFrontOnFocus;
		flags |= ImGuiWindowFlags_NoMove;

		ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.f);
		WinGui::Begin(name, nullptr, WinGuiLayer_Base, flags);
		ImGui::PopStyleVar();
	}

	void EndFullWindow() {
		WinGui::End();
	}

	void Icon(const char* icon) {
		auto* ctx = GetCurrentContext();
		IM_ASSERT(ctx && "Context is nullptr");

		ImGui::PushFont(ctx->Typography.IconFont);

		ImGui::Text(icon);

		ImGui::PopFont(); 
	}

	void IconText(const char* icon, const char* text, int spacing)
	{
		auto* ctx = GetCurrentContext();
		IM_ASSERT(ctx && "Context is nullptr");

		ImGui::PushFont(ctx->Typography.IconFont);

		ImGui::Text(icon);

		ImGui::PopFont(); 

		ImGui::SameLine();

		WinGui::SpacingX(spacing ? spacing : ImGui::GetTextLineHeight() / 4.f);

		ImGui::PushFont(ctx->Typography.TextFont);

		ImGui::Text(text);

		ImGui::PopFont(); 
	}

	ImVec2 CalcIconTextSize(const char* icon, const char* text, int spacing) {
		auto* ctx = GetCurrentContext();
		IM_ASSERT(ctx && "Context is nullptr");

		ImVec2 result = {};

		ImGui::PushFont(ctx->Typography.IconFont);

		result = ImGui::CalcTextSize(icon);

		ImGui::PopFont(); 

		result.x += (spacing ? spacing : ImGui::GetTextLineHeight() / 4.f);

		ImGui::PushFont(ctx->Typography.TextFont);

		auto text_size = ImGui::CalcTextSize(text);

		result.x += text_size.x;
		result.y = std::max(text_size.y, result.y);

		ImGui::PopFont(); 

		return result;
	}

	bool Button(const char* text, WinGuiButton_ button, ImFont *font, ImGuiButtonFlags flags) {
		auto* ctx = GetCurrentContext();
		IM_ASSERT(ctx && "Context is nullptr");

		auto& button_states = ctx->Style.ButtonStyles[button];

		ImGui::PushStyleColor(ImGuiCol_Button,        button_states[WinGuiWidgetState_Rest].Color);
		ImGui::PushStyleColor(ImGuiCol_ButtonHovered, button_states[WinGuiWidgetState_Hover].Color);
		ImGui::PushStyleColor(ImGuiCol_ButtonActive,  button_states[WinGuiWidgetState_Pressed].Color);
		ImGui::PushStyleColor(ImGuiCol_Text,          button_states[WinGuiWidgetState_Rest].ContentColor);
		ImGui::PushStyleColor(ImGuiCol_Border,        button_states[WinGuiWidgetState_Rest].OutlineColor);

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

	ImVec2 CalcTextSize(const char* text, ImFont* font) {
		ImGui::PushFont(font);
		auto result = ImGui::CalcTextSize(text);
		ImGui::PopFont();
		return result;
	}

	bool IconTextButton(const char *icon, const char* text, WinGuiButton_ button, ImGuiButtonFlags flags){
		ImGuiWindow* window = ImGui::GetCurrentWindow();
		if (window->SkipItems)
			return false;

		auto* ctx = GetCurrentContext();
		IM_ASSERT(ctx && "Context is nullptr");

		auto& button_states = ctx->Style.ButtonStyles[button];

		ImGui::PushStyleColor(ImGuiCol_Button,        button_states[WinGuiWidgetState_Rest].Color);
		ImGui::PushStyleColor(ImGuiCol_ButtonHovered, button_states[WinGuiWidgetState_Hover].Color);
		ImGui::PushStyleColor(ImGuiCol_ButtonActive,  button_states[WinGuiWidgetState_Pressed].Color);
		ImGui::PushStyleColor(ImGuiCol_Text,          button_states[WinGuiWidgetState_Rest].ContentColor);
		ImGui::PushStyleColor(ImGuiCol_Border,        button_states[WinGuiWidgetState_Rest].OutlineColor);



		ImGuiContext& g = *GImGui;
		const ImGuiStyle& style = g.Style;
		const ImGuiID id = window->GetID(text);

		auto icon_text_spacing = 10.f;

		const ImVec2 icon_size = CalcTextSize(icon, ctx->Typography.IconFont);
		const ImVec2 text_size = CalcTextSize(text, ctx->Typography.TextFont);
		const ImVec2 label_size = {icon_size.x + icon_text_spacing + text_size.x, std::max(icon_size.y, text_size.y)};

		ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, {12.f, 10.f});
		ImGui::PushStyleVar(ImGuiStyleVar_FrameBorderSize, 1.0f); // Включаем отрисовку аутлайна

		ImVec2 pos = window->DC.CursorPos;
		if ((flags & ImGuiButtonFlags_AlignTextBaseLine) && style.FramePadding.y < window->DC.CurrLineTextBaseOffset) // Try to vertically align buttons that are smaller/have no padding so that text baseline matches (bit hacky, since it shouldn't be a flag)
			pos.y += window->DC.CurrLineTextBaseOffset - style.FramePadding.y;
		ImVec2 size = ImGui::CalcItemSize({0.f, 0.f}, label_size.x + style.FramePadding.x * 2.0f, label_size.y + style.FramePadding.y * 2.0f);

		const ImRect bb(pos, pos + size);
		ImGui::ItemSize(size, style.FramePadding.y);
		if (!ImGui::ItemAdd(bb, id)){
			ImGui::PopStyleVar(2);
			ImGui::PopStyleColor(5);

			return false;
		}

		bool hovered, held;
		bool pressed = ImGui::ButtonBehavior(bb, id, &hovered, &held, flags);

		const ImU32 col = ImGui::GetColorU32((held && hovered) ? ImGuiCol_ButtonActive : hovered ? ImGuiCol_ButtonHovered : ImGuiCol_Button);
		ImGui::RenderNavCursor(bb, id);
		ImGui::RenderFrame(bb.Min, bb.Max, col, true, style.FrameRounding);

		if (g.LogEnabled)
			ImGui::LogSetNextTextDecoration("[", "]");
		
		ImGui::PushFont(ctx->Typography.IconFont);
		ImGui::RenderTextClipped(bb.Min + style.FramePadding, bb.Max - style.FramePadding, icon, NULL, &label_size, style.ButtonTextAlign, &bb);
		ImGui::PopFont();
		ImGui::PushFont(ctx->Typography.TextFont);
		ImGui::RenderTextClipped(bb.Min + style.FramePadding + ImVec2(icon_size.x + icon_text_spacing, 0), bb.Max - style.FramePadding, text, NULL, &label_size, style.ButtonTextAlign, &bb);
		ImGui::PopFont();

		ImGui::PopStyleVar(2);
		ImGui::PopStyleColor(5);

		return pressed;
	}

	std::tuple<bool, bool, bool> WindowControlButtons(const char *minimize_icon, const char *maximize_icon, const char *close_icon) {
		auto* ctx = GetCurrentContext();
		IM_ASSERT(ctx && "Context is nullptr");

		ImGui::BeginGroup();

		ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, {0.f, 0.f});
		ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 0.f);
		
		bool minimize = WinGui::SubtleIconButton(minimize_icon);

		ImGui::SameLine();

		bool maximize = WinGui::SubtleIconButton(maximize_icon);

		ImGui::SameLine();

		const auto &subtleRest = ctx->Style.ButtonStyles[WinGuiButton_Subtle][WinGuiWidgetState_Rest];
		auto &destructiveRest = ctx->Style.ButtonStyles[WinGuiButton_Destructive][WinGuiWidgetState_Rest];
		
		auto restBackup = destructiveRest;
		destructiveRest = subtleRest;

		bool close = WinGui::DestructiveIconButton(close_icon);
		
		destructiveRest = restBackup;

		ImGui::SameLine();

		ImGui::PopStyleVar(2);

		ImGui::EndGroup();

		return {minimize, maximize, close};
	}

	void OpenPopup(const char* name){
		ImGui::OpenPopup(name);
	}

	bool BeginPopup(const char* name, WinGuiPopup_ type){
		auto* ctx = GetCurrentContext();
		IM_ASSERT(ctx && "Context is nullptr");

		if (!ImGui::IsPopupOpen(name)) {
			return false;
		}
		
		auto rect_min = ImGui::GetItemRectMin();
		auto rect_max = ImGui::GetItemRectMax();

		if(type == WinGuiPopup_Over)
			ImGui::SetNextWindowPos(rect_min);

		if(type == WinGuiPopup_Below)
			ImGui::SetNextWindowPos({rect_min.x, rect_max.y});

		ImGui::PushStyleColor(ImGuiCol_PopupBg, ctx->Style.LayerStyles[WinGuiLayer_Content].Color);
		//ImGui::PushStyleColor(ImGuiCol_Border, ctx->Style.LayerStyles[WinGuiLayer_Content].OutlineColor);
		//ImGui::PushStyleColor(ImGuiCol_BorderShadow, ctx->Style.LayerStyles[WinGuiLayer_Content].ShadowColor);

		return ImGui::BeginPopup(name);
	}

	void EndPopup() {
		ImGui::EndPopup();

		ImGui::PopStyleColor(/*3*/);
	}

	void SpacingX(int spacing)
	{
        ImGui::SetCursorPos({ImGui::GetCursorPos().x + spacing, ImGui::GetCursorPosY()});
	}

	void Checkbox(const char* name, bool* v)
	{
		auto* ctx = GetCurrentContext();
		IM_ASSERT(ctx && "Context is nullptr");

		IM_ASSERT(v && "v is nullptr");

		auto& style = *v ? ctx->Style.CheckboxStyles[WinGuiCheckbox_Checked] : ctx->Style.CheckboxStyles[WinGuiCheckbox_Unchecked];

		ImGui::PushStyleColor(ImGuiCol_FrameBg,        style[WinGuiWidgetState_Rest].Color);
		ImGui::PushStyleColor(ImGuiCol_FrameBgHovered, style[WinGuiWidgetState_Hover].Color);
		ImGui::PushStyleColor(ImGuiCol_FrameBgActive,  style[WinGuiWidgetState_Pressed].Color);
		ImGui::PushStyleColor(ImGuiCol_Border,         style[WinGuiWidgetState_Rest].OutlineColor);
		ImGui::PushStyleColor(ImGuiCol_CheckMark,      ctx->Style.CheckboxStyles[WinGuiCheckbox_Checked][WinGuiWidgetState_Rest].ContentColor);

		ImGui::PushStyleVar(ImGuiStyleVar_FrameBorderSize, 1.0f);

		ImGui::Checkbox(name, v);

		ImGui::PopStyleVar();

		ImGui::PopStyleColor(5);

	}

	void RadioButton(const char* name, bool active) {
		auto* ctx = GetCurrentContext();
		IM_ASSERT(ctx && "Context is nullptr");

		auto& style = active ? ctx->Style.RadioButtonStyles[WinGuiRadioButton_Active] : ctx->Style.RadioButtonStyles[WinGuiRadioButton_Unactive];

		ImGui::PushStyleColor(ImGuiCol_FrameBg,        style[WinGuiWidgetState_Rest].Color);
		ImGui::PushStyleColor(ImGuiCol_FrameBgHovered, style[WinGuiWidgetState_Hover].Color);
		ImGui::PushStyleColor(ImGuiCol_FrameBgActive,  style[WinGuiWidgetState_Pressed].Color);
		ImGui::PushStyleColor(ImGuiCol_Border,         style[WinGuiWidgetState_Rest].OutlineColor);
		ImGui::PushStyleColor(ImGuiCol_CheckMark,      ctx->Style.RadioButtonStyles[WinGuiRadioButton_Active][WinGuiWidgetState_Rest].ContentColor);

		ImGui::PushStyleVar(ImGuiStyleVar_FrameBorderSize, 1.0f);

		ImGui::RadioButton(name, active);

		ImGui::PopStyleVar();

		ImGui::PopStyleColor(5);
	}
}