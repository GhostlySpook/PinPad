#pragma once

namespace Pinned {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Settings
	/// </summary>
	public ref class Settings : public System::Windows::Forms::Form
	{
	public:
		Settings(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Settings()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Drawing::Color backgroundcolor;
	public: int transparency = 0;

	private: System::Windows::Forms::Button^  btn_backcolor;
	private: System::Windows::Forms::TrackBar^  tbar_transparency;
	protected:

	protected:

	private: System::Windows::Forms::Label^  lbl_transparency;

	private: System::Windows::Forms::Button^  btn_accept;
	private: System::Windows::Forms::Button^  btn_cancel;
	private: System::Windows::Forms::NumericUpDown^  nup_transparency;
	private: System::Windows::Forms::Label^  label1;



	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Settings::typeid));
			this->btn_backcolor = (gcnew System::Windows::Forms::Button());
			this->tbar_transparency = (gcnew System::Windows::Forms::TrackBar());
			this->lbl_transparency = (gcnew System::Windows::Forms::Label());
			this->btn_accept = (gcnew System::Windows::Forms::Button());
			this->btn_cancel = (gcnew System::Windows::Forms::Button());
			this->nup_transparency = (gcnew System::Windows::Forms::NumericUpDown());
			this->label1 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tbar_transparency))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nup_transparency))->BeginInit();
			this->SuspendLayout();
			// 
			// btn_backcolor
			// 
			this->btn_backcolor->Location = System::Drawing::Point(21, 35);
			this->btn_backcolor->Name = L"btn_backcolor";
			this->btn_backcolor->Size = System::Drawing::Size(167, 23);
			this->btn_backcolor->TabIndex = 0;
			this->btn_backcolor->Text = L"Change background color";
			this->btn_backcolor->UseVisualStyleBackColor = true;
			this->btn_backcolor->Click += gcnew System::EventHandler(this, &Settings::btn_backcolor_Click);
			// 
			// tbar_transparency
			// 
			this->tbar_transparency->LargeChange = 51;
			this->tbar_transparency->Location = System::Drawing::Point(21, 100);
			this->tbar_transparency->Maximum = 255;
			this->tbar_transparency->Name = L"tbar_transparency";
			this->tbar_transparency->Size = System::Drawing::Size(167, 45);
			this->tbar_transparency->TabIndex = 1;
			this->tbar_transparency->TickFrequency = 17;
			this->tbar_transparency->Scroll += gcnew System::EventHandler(this, &Settings::tbar_transparency_Scroll);
			// 
			// lbl_transparency
			// 
			this->lbl_transparency->AutoSize = true;
			this->lbl_transparency->ForeColor = System::Drawing::Color::White;
			this->lbl_transparency->Location = System::Drawing::Point(67, 84);
			this->lbl_transparency->Name = L"lbl_transparency";
			this->lbl_transparency->Size = System::Drawing::Size(72, 13);
			this->lbl_transparency->TabIndex = 2;
			this->lbl_transparency->Text = L"Transparency";
			// 
			// btn_accept
			// 
			this->btn_accept->Location = System::Drawing::Point(21, 188);
			this->btn_accept->Name = L"btn_accept";
			this->btn_accept->Size = System::Drawing::Size(75, 23);
			this->btn_accept->TabIndex = 3;
			this->btn_accept->Text = L"Accept";
			this->btn_accept->UseVisualStyleBackColor = true;
			this->btn_accept->Click += gcnew System::EventHandler(this, &Settings::btn_accept_Click);
			// 
			// btn_cancel
			// 
			this->btn_cancel->Location = System::Drawing::Point(113, 188);
			this->btn_cancel->Name = L"btn_cancel";
			this->btn_cancel->Size = System::Drawing::Size(75, 23);
			this->btn_cancel->TabIndex = 4;
			this->btn_cancel->Text = L"Cancel";
			this->btn_cancel->UseVisualStyleBackColor = true;
			this->btn_cancel->Click += gcnew System::EventHandler(this, &Settings::btn_cancel_Click);
			// 
			// nup_transparency
			// 
			this->nup_transparency->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->nup_transparency->Location = System::Drawing::Point(80, 138);
			this->nup_transparency->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 255, 0, 0, 0 });
			this->nup_transparency->Name = L"nup_transparency";
			this->nup_transparency->Size = System::Drawing::Size(48, 20);
			this->nup_transparency->TabIndex = 5;
			this->nup_transparency->ValueChanged += gcnew System::EventHandler(this, &Settings::nup_transparency_ValueChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->ForeColor = System::Drawing::SystemColors::ControlDark;
			this->label1->Location = System::Drawing::Point(126, 222);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(75, 13);
			this->label1->TabIndex = 6;
			this->label1->Text = L"ghostly_spook";
			// 
			// Settings
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->ClientSize = System::Drawing::Size(213, 244);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->nup_transparency);
			this->Controls->Add(this->btn_cancel);
			this->Controls->Add(this->btn_accept);
			this->Controls->Add(this->lbl_transparency);
			this->Controls->Add(this->tbar_transparency);
			this->Controls->Add(this->btn_backcolor);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Settings";
			this->SizeGripStyle = System::Windows::Forms::SizeGripStyle::Hide;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Settings";
			this->Load += gcnew System::EventHandler(this, &Settings::Settings_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tbar_transparency))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nup_transparency))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btn_accept_Click(System::Object^  sender, System::EventArgs^  e) {
		if(transparency == 69)
		System::Windows::Forms::MessageBox::Show("(. . ) ", "420", MessageBoxButtons::OK);
		this->DialogResult = System::Windows::Forms::DialogResult::OK;
		this->Close();
	}
private: System::Void btn_cancel_Click(System::Object^  sender, System::EventArgs^  e) {
	this->DialogResult = System::Windows::Forms::DialogResult::Cancel;
	this->Close();
}
private: System::Void btn_backcolor_Click(System::Object^  sender, System::EventArgs^  e) {
	ColorDialog ^ dlgColor = gcnew ColorDialog;
	
	if (dlgColor->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		backgroundcolor = dlgColor->Color;
	}
}
private: System::Void nup_transparency_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
	transparency = (int)nup_transparency->Value;
	tbar_transparency->Value = transparency;
}
private: System::Void tbar_transparency_Scroll(System::Object^  sender, System::EventArgs^  e) {
	transparency = tbar_transparency->Value;
	nup_transparency->Value = transparency;
}
private: System::Void Settings_Load(System::Object^  sender, System::EventArgs^  e) {
	tbar_transparency->Value = transparency;
	nup_transparency->Value = transparency;
}
};
}
