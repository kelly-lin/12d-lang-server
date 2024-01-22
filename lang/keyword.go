package lang

import "github.com/kelly-lin/12d-lang-server/protocol"

var KeywordCompletionItems = []protocol.CompletionItem{
	{Label: "for", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "do", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "while", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "if", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "else", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "goto", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "switch", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "default", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "case", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "return", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "include", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "define", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
}

var TypeCompletionItems = []protocol.CompletionItem{
	{Label: "Angle_Box", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "Apply_Function", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "Apply_Many_Function", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "Arc", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "Attribute", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "Attribute_Blob", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "Attributes", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "Attributes_Box", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "Billboard_Box", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "Bitmap_Fill_Box", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "Bitmap_List_Box", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "Button", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "Chainage_Box", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "Choice_Box", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "Colour_Box", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "Colour_Message_Box", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "Connection", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "Curve", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "Database_Result", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "Date_Time_Box", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "Delete_Query", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "Directory_Box", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "Drainage_Network", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "Draw_Box", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "Dynamic_Element", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "Dynamic_Integer", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "Dynamic_Real", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "Dynamic_Text", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "Element", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "Equality_Info", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "Equality_Label", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "File", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "File_Box", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "Function", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "Function_Box", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "Function_Property_Collection", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "Graph_Box", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "GridCtrl_Box", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "Guid", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "Horizontal_Group", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "HyperLink_Box", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "Input_Box", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "Insert_Query", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "Integer", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "Integer64", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "Integer_Box", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "Integer_Set", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "Justify_Box", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "Kerb_Return_Function", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "Line", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "Linestyle_Box", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "List", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "ListCtrl_Box", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "List_Box", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "Log_Box", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "Log_Line", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "Macro_Function", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "Manual_Condition", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "Manual_Query", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "Map_File", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "Map_File_Box", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "Matrix3", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "Matrix4", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "Menu", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "Message_Box", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "Model", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "Model_Box", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "Name_Box", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "Named_Tick_Box", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "Names", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "New_Select_Box", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "New_XYZ_Box", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "Overlay_Widget", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "Panel", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "Parabola", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "Parameter_Collection", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "Plot_Parameter_File", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "Plotter_Box", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "Point", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "Polygon_Box", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "Process_Handle", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "Query_Condition", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "Real_Box", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "Real", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "Real_Set", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "Report_Box", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "SDR_Attribute", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "Screen_Text", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "Segment", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "Select_Box", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "Select_Boxes", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "Select_Button", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "Select_Query", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "Selection", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "Sheet_Panel", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "Sheet_Size_Box", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "Slider_Box", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "Source_Box", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "Spiral", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "String", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "Symbol_Box", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "Tab_Box", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "Target_Box", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "Template_Box", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "Text", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "Text_Edit_Box", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "Text_Set", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "Text_Style_Box", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "Text_Units_Box", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "Textstyle_Data", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "Textstyle_Data_Box", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "Texture_Box", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "Tick_Box", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "Time_Zone_Box", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "Time_Zone_Box_Box", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "Tin", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "Tin_Box", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "Transaction", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "Tree_Box", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "Tree_Page", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "Uid", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "Undo", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "Undo_List", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "Update_Query", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "Vector2", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "Vector3", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "Vector4", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "Vertical_Group", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "View", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "View_Box", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "Widget", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "Widget_Pages", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "XML_Document", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "XML_Node", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "XYZ_Box", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
	{Label: "void", Kind: protocol.GetCompletionItemKind(protocol.CompletionItemKindKeyword), Documentation: &protocol.MarkupContent{Kind: protocol.MarkupKindPlainText, Value: ""}},
}
