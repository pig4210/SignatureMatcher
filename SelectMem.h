#pragma once

namespace SignatureMatcher {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// SelectMem 摘要
	/// </summary>
	public ref class SelectMem : public System::Windows::Forms::Form
	{
	public:
		SelectMem(void)
		{
			InitializeComponent();
			//
			//TODO:  在此处添加构造函数代码
			//
		}

	protected:
		/// <summary>
		/// 清理所有正在使用的资源。
		/// </summary>
		~SelectMem()
		{
			if (components)
			{
				delete components;
			}
		}

  protected:

  protected:
  private: System::Windows::Forms::Button^  Btn_Ok;
  private: System::Windows::Forms::Button^  Btn_Cancel;
  public: System::Windows::Forms::DataGridView^  DGV_mem;
  private:

  private: System::Windows::Forms::DataGridViewTextBoxColumn^  Col_Start;
  private: System::Windows::Forms::DataGridViewTextBoxColumn^  Col_End;
  private: System::Windows::Forms::DataGridViewTextBoxColumn^  Col_Path;



	private:
		/// <summary>
		/// 必需的设计器变量。
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 设计器支持所需的方法 - 不要
		/// 使用代码编辑器修改此方法的内容。
		/// </summary>
		void InitializeComponent(void)
		{
    System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
    System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
    System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
    System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle4 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
    System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle5 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
    System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(SelectMem::typeid));
    this->Btn_Ok = (gcnew System::Windows::Forms::Button());
    this->Btn_Cancel = (gcnew System::Windows::Forms::Button());
    this->DGV_mem = (gcnew System::Windows::Forms::DataGridView());
    this->Col_Start = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
    this->Col_End = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
    this->Col_Path = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
    (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DGV_mem))->BeginInit();
    this->SuspendLayout();
    // 
    // Btn_Ok
    // 
    this->Btn_Ok->DialogResult = System::Windows::Forms::DialogResult::OK;
    this->Btn_Ok->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
    this->Btn_Ok->Location = System::Drawing::Point(359, 243);
    this->Btn_Ok->Name = L"Btn_Ok";
    this->Btn_Ok->Size = System::Drawing::Size(75, 23);
    this->Btn_Ok->TabIndex = 1;
    this->Btn_Ok->Text = L"确定(&K)";
    this->Btn_Ok->UseVisualStyleBackColor = true;
    // 
    // Btn_Cancel
    // 
    this->Btn_Cancel->DialogResult = System::Windows::Forms::DialogResult::Cancel;
    this->Btn_Cancel->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
    this->Btn_Cancel->Location = System::Drawing::Point(440, 243);
    this->Btn_Cancel->Name = L"Btn_Cancel";
    this->Btn_Cancel->Size = System::Drawing::Size(75, 23);
    this->Btn_Cancel->TabIndex = 2;
    this->Btn_Cancel->Text = L"关闭(&X)";
    this->Btn_Cancel->UseVisualStyleBackColor = true;
    // 
    // DGV_mem
    // 
    this->DGV_mem->AllowUserToAddRows = false;
    this->DGV_mem->AllowUserToDeleteRows = false;
    this->DGV_mem->AllowUserToResizeColumns = false;
    this->DGV_mem->AllowUserToResizeRows = false;
    dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
    dataGridViewCellStyle1->BackColor = System::Drawing::Color::DimGray;
    dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"宋体", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
      static_cast<System::Byte>(134)));
    dataGridViewCellStyle1->ForeColor = System::Drawing::Color::White;
    this->DGV_mem->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle1;
    this->DGV_mem->BackgroundColor = System::Drawing::Color::Black;
    this->DGV_mem->BorderStyle = System::Windows::Forms::BorderStyle::None;
    this->DGV_mem->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
    dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
    dataGridViewCellStyle2->BackColor = System::Drawing::Color::Black;
    dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"宋体", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
      static_cast<System::Byte>(134)));
    dataGridViewCellStyle2->ForeColor = System::Drawing::Color::Silver;
    dataGridViewCellStyle2->SelectionBackColor = System::Drawing::SystemColors::Highlight;
    dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
    dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
    this->DGV_mem->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle2;
    this->DGV_mem->ColumnHeadersHeight = 21;
    this->DGV_mem->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::DisableResizing;
    this->DGV_mem->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3)
      {
      this->Col_Start, this->Col_End,
        this->Col_Path
      });
    dataGridViewCellStyle3->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
    dataGridViewCellStyle3->BackColor = System::Drawing::Color::Black;
    dataGridViewCellStyle3->Font = (gcnew System::Drawing::Font(L"宋体", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
      static_cast<System::Byte>(134)));
    dataGridViewCellStyle3->ForeColor = System::Drawing::Color::Silver;
    dataGridViewCellStyle3->SelectionBackColor = System::Drawing::SystemColors::Highlight;
    dataGridViewCellStyle3->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
    dataGridViewCellStyle3->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
    this->DGV_mem->DefaultCellStyle = dataGridViewCellStyle3;
    this->DGV_mem->Dock = System::Windows::Forms::DockStyle::Fill;
    this->DGV_mem->EnableHeadersVisualStyles = false;
    this->DGV_mem->GridColor = System::Drawing::Color::Green;
    this->DGV_mem->Location = System::Drawing::Point(0, 0);
    this->DGV_mem->MultiSelect = false;
    this->DGV_mem->Name = L"DGV_mem";
    this->DGV_mem->ReadOnly = true;
    dataGridViewCellStyle4->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
    dataGridViewCellStyle4->BackColor = System::Drawing::Color::Black;
    dataGridViewCellStyle4->Font = (gcnew System::Drawing::Font(L"宋体", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
      static_cast<System::Byte>(134)));
    dataGridViewCellStyle4->ForeColor = System::Drawing::Color::Silver;
    dataGridViewCellStyle4->SelectionBackColor = System::Drawing::SystemColors::Highlight;
    dataGridViewCellStyle4->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
    dataGridViewCellStyle4->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
    this->DGV_mem->RowHeadersDefaultCellStyle = dataGridViewCellStyle4;
    this->DGV_mem->RowHeadersVisible = false;
    this->DGV_mem->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::DisableResizing;
    dataGridViewCellStyle5->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
    dataGridViewCellStyle5->BackColor = System::Drawing::Color::Black;
    dataGridViewCellStyle5->ForeColor = System::Drawing::Color::Silver;
    this->DGV_mem->RowsDefaultCellStyle = dataGridViewCellStyle5;
    this->DGV_mem->RowTemplate->DefaultCellStyle->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
    this->DGV_mem->RowTemplate->DefaultCellStyle->BackColor = System::Drawing::Color::Black;
    this->DGV_mem->RowTemplate->DefaultCellStyle->ForeColor = System::Drawing::Color::Silver;
    this->DGV_mem->RowTemplate->Height = 18;
    this->DGV_mem->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
    this->DGV_mem->ShowEditingIcon = false;
    this->DGV_mem->Size = System::Drawing::Size(525, 269);
    this->DGV_mem->TabIndex = 0;
    this->DGV_mem->Tag = L"";
    this->DGV_mem->DoubleClick += gcnew System::EventHandler(this, &SelectMem::DGV_mem_DoubleClick);
    this->DGV_mem->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &SelectMem::DGV_mem_KeyDown);
    // 
    // Col_Start
    // 
    this->Col_Start->HeaderText = L"起始地址";
    this->Col_Start->MaxInputLength = 24;
    this->Col_Start->Name = L"Col_Start";
    this->Col_Start->ReadOnly = true;
    this->Col_Start->Width = 120;
    // 
    // Col_End
    // 
    this->Col_End->HeaderText = L"结束地址";
    this->Col_End->MaxInputLength = 24;
    this->Col_End->Name = L"Col_End";
    this->Col_End->ReadOnly = true;
    this->Col_End->Width = 120;
    // 
    // Col_Path
    // 
    this->Col_Path->HeaderText = L"模块路径";
    this->Col_Path->Name = L"Col_Path";
    this->Col_Path->ReadOnly = true;
    this->Col_Path->Width = 265;
    // 
    // SelectMem
    // 
    this->AcceptButton = this->Btn_Ok;
    this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
    this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
    this->BackColor = System::Drawing::Color::Black;
    this->CancelButton = this->Btn_Cancel;
    this->ClientSize = System::Drawing::Size(525, 269);
    this->Controls->Add(this->Btn_Cancel);
    this->Controls->Add(this->Btn_Ok);
    this->Controls->Add(this->DGV_mem);
    this->ForeColor = System::Drawing::Color::Silver;
    this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
    this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
    this->MaximizeBox = false;
    this->Name = L"SelectMem";
    this->Opacity = 0.8;
    this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
    this->Text = L"选择内存范围";
    this->TopMost = true;
    this->Load += gcnew System::EventHandler(this, &SelectMem::SelectMem_Load);
    (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DGV_mem))->EndInit();
    this->ResumeLayout(false);

      }
#pragma endregion
  private: System::Void SelectMem_Load(System::Object^  sender, System::EventArgs^  e);
  private: System::Void DGV_mem_DoubleClick(System::Object^  sender, System::EventArgs^  e);
  private: System::Void DGV_mem_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e);
};
}
