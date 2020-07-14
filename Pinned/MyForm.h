#pragma once

namespace Pinned {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	//using namespace System::Windows::Shell;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			SetStyle(ControlStyles::SupportsTransparentBackColor, true);
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^  ms_main;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  mi_new;
	private: System::Windows::Forms::ToolStripMenuItem^  mi_newwin;
	private: System::Windows::Forms::ToolStripMenuItem^  mi_open;
	private: System::Windows::Forms::ToolStripMenuItem^  mi_save;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator1;
	private: System::Windows::Forms::ToolStripMenuItem^  mi_settings;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator2;
	private: System::Windows::Forms::ToolStripMenuItem^  mi_exit;
	private: System::Windows::Forms::ToolStripMenuItem^  mi_font;
	private: System::Windows::Forms::ToolStripMenuItem^  mi_pin;
	private: System::Windows::Forms::TextBox^  txt_main;

	private:


	private: System::ComponentModel::IContainer^  components;
			 //	private: System::Windows::Shell::TaskbarItemInfo^ tbar_info;






	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->ms_main = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mi_new = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mi_newwin = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mi_open = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mi_save = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->mi_settings = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator2 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->mi_exit = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mi_font = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mi_pin = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->txt_main = (gcnew System::Windows::Forms::TextBox());
			this->ms_main->SuspendLayout();
			this->SuspendLayout();
			// 
			// ms_main
			// 
			this->ms_main->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->fileToolStripMenuItem,
					this->mi_font, this->mi_pin
			});
			this->ms_main->Location = System::Drawing::Point(0, 0);
			this->ms_main->Name = L"ms_main";
			this->ms_main->Size = System::Drawing::Size(454, 24);
			this->ms_main->TabIndex = 0;
			this->ms_main->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(8) {
				this->mi_new,
					this->mi_newwin, this->mi_open, this->mi_save, this->toolStripSeparator1, this->mi_settings, this->toolStripSeparator2, this->mi_exit
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// mi_new
			// 
			this->mi_new->Name = L"mi_new";
			this->mi_new->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::N));
			this->mi_new->Size = System::Drawing::Size(234, 22);
			this->mi_new->Text = L"New";
			this->mi_new->Click += gcnew System::EventHandler(this, &MyForm::mi_new_Click);
			// 
			// mi_newwin
			// 
			this->mi_newwin->Name = L"mi_newwin";
			this->mi_newwin->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Shift)
				| System::Windows::Forms::Keys::N));
			this->mi_newwin->Size = System::Drawing::Size(234, 22);
			this->mi_newwin->Text = L"New Window";
			this->mi_newwin->Click += gcnew System::EventHandler(this, &MyForm::mi_newwin_Click);
			// 
			// mi_open
			// 
			this->mi_open->Name = L"mi_open";
			this->mi_open->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::O));
			this->mi_open->Size = System::Drawing::Size(234, 22);
			this->mi_open->Text = L"Open...";
			this->mi_open->Click += gcnew System::EventHandler(this, &MyForm::mi_open_Click);
			// 
			// mi_save
			// 
			this->mi_save->Name = L"mi_save";
			this->mi_save->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::S));
			this->mi_save->Size = System::Drawing::Size(234, 22);
			this->mi_save->Text = L"Save";
			this->mi_save->Click += gcnew System::EventHandler(this, &MyForm::mi_save_Click);
			// 
			// toolStripSeparator1
			// 
			this->toolStripSeparator1->Name = L"toolStripSeparator1";
			this->toolStripSeparator1->Size = System::Drawing::Size(231, 6);
			// 
			// mi_settings
			// 
			this->mi_settings->Name = L"mi_settings";
			this->mi_settings->Size = System::Drawing::Size(234, 22);
			this->mi_settings->Text = L"Settings";
			this->mi_settings->Click += gcnew System::EventHandler(this, &MyForm::mi_settings_Click);
			// 
			// toolStripSeparator2
			// 
			this->toolStripSeparator2->Name = L"toolStripSeparator2";
			this->toolStripSeparator2->Size = System::Drawing::Size(231, 6);
			// 
			// mi_exit
			// 
			this->mi_exit->Name = L"mi_exit";
			this->mi_exit->Size = System::Drawing::Size(234, 22);
			this->mi_exit->Text = L"Exit";
			this->mi_exit->Click += gcnew System::EventHandler(this, &MyForm::mi_exit_Click);
			// 
			// mi_font
			// 
			this->mi_font->Name = L"mi_font";
			this->mi_font->Size = System::Drawing::Size(43, 20);
			this->mi_font->Text = L"Font";
			this->mi_font->Click += gcnew System::EventHandler(this, &MyForm::mi_font_Click);
			// 
			// mi_pin
			// 
			this->mi_pin->Name = L"mi_pin";
			this->mi_pin->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::P));
			this->mi_pin->Size = System::Drawing::Size(36, 20);
			this->mi_pin->Text = L"Pin";
			this->mi_pin->Click += gcnew System::EventHandler(this, &MyForm::mi_pin_Click);
			// 
			// txt_main
			// 
			this->txt_main->AcceptsReturn = true;
			this->txt_main->AcceptsTab = true;
			this->txt_main->BackColor = System::Drawing::Color::White;
			this->txt_main->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->txt_main->Dock = System::Windows::Forms::DockStyle::Fill;
			this->txt_main->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txt_main->ForeColor = System::Drawing::Color::Navy;
			this->txt_main->Location = System::Drawing::Point(0, 24);
			this->txt_main->Multiline = true;
			this->txt_main->Name = L"txt_main";
			this->txt_main->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->txt_main->Size = System::Drawing::Size(454, 237);
			this->txt_main->TabIndex = 1;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::DarkGray;
			this->ClientSize = System::Drawing::Size(454, 261);
			this->Controls->Add(this->txt_main);
			this->Controls->Add(this->ms_main);
			this->ForeColor = System::Drawing::SystemColors::Desktop;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->ms_main;
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->Text = L"PinPad";
			this->TransparencyKey = System::Drawing::Color::Transparent;
			this->Activated += gcnew System::EventHandler(this, &MyForm::MyForm_Activated);
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ms_main->ResumeLayout(false);
			this->ms_main->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	protected: virtual void WndProc(Message% m) override{
		if (m.Msg == WM_HOTKEY && m.WParam.ToInt32() == 1) {
			if (pin == true)
			{
				removepin(this, ms_main, txt_main);
			}
			else if (pin == false)
			{
				setpin(this, ms_main, txt_main);
			}
		}
		__super::WndProc(m);
	}

	private: System::Void mi_newwin_Click(System::Object^  sender, System::EventArgs^  e) {
		startup();
	}
	private: System::Void mi_save_Click(System::Object^  sender, System::EventArgs^  e) {
		save(txt_main);
	}
	private: System::Void mi_exit_Click(System::Object^  sender, System::EventArgs^  e) {
		Close();
	}
	private: System::Void mi_font_Click(System::Object^  sender, System::EventArgs^  e) {
		showfontdial(txt_main);
	}
	private: System::Void mi_pin_Click(System::Object^  sender, System::EventArgs^  e) {
		if (pin == true)
		{
			removepin(this, ms_main, txt_main);
		}
		else if (pin == false)
		{
			setpin(this, ms_main, txt_main);
		}
	}
	private: System::Void MyForm_Activated(System::Object^  sender, System::EventArgs^  e) {
		removepin(this, ms_main, txt_main);
	}
	private: System::Void mi_open_Click(System::Object^  sender, System::EventArgs^  e) {
		loadtext(txt_main);
	}
	private: System::Void mi_settings_Click(System::Object^  sender, System::EventArgs^  e) {
		showsettings(txt_main);
	}
	private: System::Void mi_new_Click(System::Object^  sender, System::EventArgs^  e) {
		newdoc(txt_main);
	}
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
		RegisterHotKey((HWND)this->Handle.ToPointer(), 1,
			MOD_ALT | MOD_CONTROL, (UINT)Keys::B);
		loadsettings(txt_main);
		hwnd = static_cast<HWND>(this->Handle.ToPointer());
		inst = GetModuleHandle(NULL);	
	}
};
}
