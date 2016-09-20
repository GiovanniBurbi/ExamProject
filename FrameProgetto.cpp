///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Feb 16 2016)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "FrameProgetto.h"

///////////////////////////////////////////////////////////////////////////

MainFrame::MainFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxVERTICAL );
	
	textFiles = new wxStaticText( this, wxID_ANY, wxT("Downloading FIles..."), wxDefaultPosition, wxDefaultSize, 0 );
	textFiles->Wrap( -1 );
	bSizer8->Add( textFiles, 0, wxALL, 20 );
	
	gaugeFiles = new wxGauge( this, wxID_ANY, 100, wxDefaultPosition, wxDefaultSize, wxGA_SMOOTH );
	gaugeFiles->SetValue( 0 ); 
	bSizer8->Add( gaugeFiles, 0, wxEXPAND, 20 );
	
	textBytes = new wxStaticText( this, wxID_ANY, wxT("Downloading Bytes..."), wxDefaultPosition, wxDefaultSize, 0 );
	textBytes->Wrap( -1 );
	bSizer8->Add( textBytes, 0, wxALL, 20 );
	
	gaugeBytes = new wxGauge( this, wxID_ANY, 100, wxDefaultPosition, wxDefaultSize, wxGA_HORIZONTAL );
	gaugeBytes->SetValue( 0 ); 
	bSizer8->Add( gaugeBytes, 0, wxEXPAND, 15 );
	
	m_buttonDownload = new wxButton( this, wxID_ANY, wxT("Download"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer8->Add( m_buttonDownload, 0, wxALL, 15 );
	
	
	this->SetSizer( bSizer8 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_buttonDownload->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnClickDownload ), NULL, this );
}

MainFrame::~MainFrame()
{
	// Disconnect Events
	m_buttonDownload->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::OnClickDownload ), NULL, this );
	
}
