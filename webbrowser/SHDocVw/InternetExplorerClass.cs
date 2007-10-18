using System;

namespace SHDocVw
{

public class InternetExplorerClass : DWebBrowserEvents_Event, DWebBrowserEvents2_Event, InternetExplorer, IWebBrowser, IWebBrowser2, IWebBrowserApp {
	
	public InternetExplorerClass ();
	
	public virtual void add_BeforeNavigate (DWebBrowserEvents_BeforeNavigateEventHandler );
	public virtual void add_BeforeNavigate2 (DWebBrowserEvents2_BeforeNavigate2EventHandler );
	public virtual void add_ClientToHostWindow (DWebBrowserEvents2_ClientToHostWindowEventHandler );
	public virtual void add_CommandStateChange (DWebBrowserEvents2_CommandStateChangeEventHandler );
	public virtual void add_DocumentComplete (DWebBrowserEvents2_DocumentCompleteEventHandler );
	public virtual void add_DownloadBegin (DWebBrowserEvents2_DownloadBeginEventHandler );
	public virtual void add_DownloadComplete (DWebBrowserEvents2_DownloadCompleteEventHandler );
	public virtual void add_FileDownload (DWebBrowserEvents2_FileDownloadEventHandler );
	public virtual void add_FrameBeforeNavigate (DWebBrowserEvents_FrameBeforeNavigateEventHandler );
	public virtual void add_FrameNavigateComplete (DWebBrowserEvents_FrameNavigateCompleteEventHandler );
	public virtual void add_FrameNewWindow (DWebBrowserEvents_FrameNewWindowEventHandler );
	public virtual void add_NavigateComplete (DWebBrowserEvents_NavigateCompleteEventHandler );
	public virtual void add_NavigateComplete2 (DWebBrowserEvents2_NavigateComplete2EventHandler );
	public virtual void add_NavigateError (DWebBrowserEvents2_NavigateErrorEventHandler );
	public virtual void add_NewWindow (DWebBrowserEvents_NewWindowEventHandler );
	public virtual void add_NewWindow2 (DWebBrowserEvents2_NewWindow2EventHandler );
	public virtual void add_NewWindow3 (DWebBrowserEvents2_NewWindow3EventHandler );
	public virtual void add_OnFullScreen (DWebBrowserEvents2_OnFullScreenEventHandler );
	public virtual void add_OnMenuBar (DWebBrowserEvents2_OnMenuBarEventHandler );
	public virtual void add_OnQuit (DWebBrowserEvents2_OnQuitEventHandler );
	public virtual void add_OnStatusBar (DWebBrowserEvents2_OnStatusBarEventHandler );
	public virtual void add_OnTheaterMode (DWebBrowserEvents2_OnTheaterModeEventHandler );
	public virtual void add_OnToolBar (DWebBrowserEvents2_OnToolBarEventHandler );
	public virtual void add_OnVisible (DWebBrowserEvents2_OnVisibleEventHandler );
	public virtual void add_PrintTemplateInstantiation (DWebBrowserEvents2_PrintTemplateInstantiationEventHandler );
	public virtual void add_PrintTemplateTeardown (DWebBrowserEvents2_PrintTemplateTeardownEventHandler );
	public virtual void add_PrivacyImpactedStateChange (DWebBrowserEvents2_PrivacyImpactedStateChangeEventHandler );
	public virtual void add_ProgressChange (DWebBrowserEvents2_ProgressChangeEventHandler );
	public virtual void add_PropertyChange (DWebBrowserEvents2_PropertyChangeEventHandler );
	public virtual void add_Quit (DWebBrowserEvents_QuitEventHandler );
	public virtual void add_SetSecureLockIcon (DWebBrowserEvents2_SetSecureLockIconEventHandler );
	public virtual void add_StatusTextChange (DWebBrowserEvents2_StatusTextChangeEventHandler );
	public virtual void add_TitleChange (DWebBrowserEvents2_TitleChangeEventHandler );
	public virtual void add_UpdatePageStatus (DWebBrowserEvents2_UpdatePageStatusEventHandler );
	public virtual void add_WindowActivate (DWebBrowserEvents_WindowActivateEventHandler );
	public virtual void add_WindowClosing (DWebBrowserEvents2_WindowClosingEventHandler );
	public virtual void add_WindowMove (DWebBrowserEvents_WindowMoveEventHandler );
	public virtual void add_WindowResize (DWebBrowserEvents_WindowResizeEventHandler );
	public virtual void add_WindowSetHeight (DWebBrowserEvents2_WindowSetHeightEventHandler );
	public virtual void add_WindowSetLeft (DWebBrowserEvents2_WindowSetLeftEventHandler );
	public virtual void add_WindowSetResizable (DWebBrowserEvents2_WindowSetResizableEventHandler );
	public virtual void add_WindowSetTop (DWebBrowserEvents2_WindowSetTopEventHandler );
	public virtual void add_WindowSetWidth (DWebBrowserEvents2_WindowSetWidthEventHandler );
	public virtual void ClientToWindow (out int pcx, out int pcy);
	public virtual void DWebBrowserEvents_Event_add_CommandStateChange (DWebBrowserEvents_CommandStateChangeEventHandler );
	public virtual void DWebBrowserEvents_Event_add_DownloadBegin (DWebBrowserEvents_DownloadBeginEventHandler );
	public virtual void DWebBrowserEvents_Event_add_DownloadComplete (DWebBrowserEvents_DownloadCompleteEventHandler );
	public virtual void DWebBrowserEvents_Event_add_ProgressChange (DWebBrowserEvents_ProgressChangeEventHandler );
	public virtual void DWebBrowserEvents_Event_add_PropertyChange (DWebBrowserEvents_PropertyChangeEventHandler );
	public virtual void DWebBrowserEvents_Event_add_StatusTextChange (DWebBrowserEvents_StatusTextChangeEventHandler );
	public virtual void DWebBrowserEvents_Event_add_TitleChange (DWebBrowserEvents_TitleChangeEventHandler );
	public virtual void DWebBrowserEvents_Event_remove_CommandStateChange (DWebBrowserEvents_CommandStateChangeEventHandler );
	public virtual void DWebBrowserEvents_Event_remove_DownloadBegin (DWebBrowserEvents_DownloadBeginEventHandler );
	public virtual void DWebBrowserEvents_Event_remove_DownloadComplete (DWebBrowserEvents_DownloadCompleteEventHandler );
	public virtual void DWebBrowserEvents_Event_remove_ProgressChange (DWebBrowserEvents_ProgressChangeEventHandler );
	public virtual void DWebBrowserEvents_Event_remove_PropertyChange (DWebBrowserEvents_PropertyChangeEventHandler );
	public virtual void DWebBrowserEvents_Event_remove_StatusTextChange (DWebBrowserEvents_StatusTextChangeEventHandler );
	public virtual void DWebBrowserEvents_Event_remove_TitleChange (DWebBrowserEvents_TitleChangeEventHandler );
	public virtual bool Equals (object o);
	public virtual void ExecWB (OLECMDID cmdID, OLECMDEXECOPT cmdexecopt, ref object pvaIn, out object pvaOut);
	protected virtual void Finalize ();
	public virtual int GetHashCode ();
	public virtual object GetProperty (string Property);
	public Type GetType ();
	public virtual void GoBack ();
	public virtual void GoForward ();
	public virtual void GoHome ();
	public virtual void GoSearch ();
	public virtual void IWebBrowserApp_ClientToWindow (out int pcx, out int pcy);
	public virtual object IWebBrowserApp_GetProperty (string Property);
	public virtual void IWebBrowserApp_GoBack ();
	public virtual void IWebBrowserApp_GoForward ();
	public virtual void IWebBrowserApp_GoHome ();
	public virtual void IWebBrowserApp_GoSearch ();
	public virtual void IWebBrowserApp_Navigate (string URL, ref object Flags, ref object TargetFrameName, ref object PostData, ref object Headers);
	public virtual void IWebBrowserApp_PutProperty (string Property, object vtValue);
	public virtual void IWebBrowserApp_Quit ();
	public virtual void IWebBrowserApp_Refresh ();
	public virtual void IWebBrowserApp_Refresh2 (ref object Level);
	public virtual void IWebBrowserApp_Stop ();
	protected object MemberwiseClone ();
	public virtual void Navigate (string URL, ref object Flags, ref object TargetFrameName, ref object PostData, ref object Headers);
	public virtual void Navigate2 (ref object URL, ref object Flags, ref object TargetFrameName, ref object PostData, ref object Headers);
	public virtual void PutProperty (string Property, object vtValue);
	public virtual OLECMDF QueryStatusWB (OLECMDID cmdID);
	public virtual void Quit ();
	public virtual void remove_BeforeNavigate (DWebBrowserEvents_BeforeNavigateEventHandler );
	public virtual void remove_BeforeNavigate2 (DWebBrowserEvents2_BeforeNavigate2EventHandler );
	public virtual void remove_ClientToHostWindow (DWebBrowserEvents2_ClientToHostWindowEventHandler );
	public virtual void remove_CommandStateChange (DWebBrowserEvents2_CommandStateChangeEventHandler );
	public virtual void remove_DocumentComplete (DWebBrowserEvents2_DocumentCompleteEventHandler );
	public virtual void remove_DownloadBegin (DWebBrowserEvents2_DownloadBeginEventHandler );
	public virtual void remove_DownloadComplete (DWebBrowserEvents2_DownloadCompleteEventHandler );
	public virtual void remove_FileDownload (DWebBrowserEvents2_FileDownloadEventHandler );
	public virtual void remove_FrameBeforeNavigate (DWebBrowserEvents_FrameBeforeNavigateEventHandler );
	public virtual void remove_FrameNavigateComplete (DWebBrowserEvents_FrameNavigateCompleteEventHandler );
	public virtual void remove_FrameNewWindow (DWebBrowserEvents_FrameNewWindowEventHandler );
	public virtual void remove_NavigateComplete (DWebBrowserEvents_NavigateCompleteEventHandler );
	public virtual void remove_NavigateComplete2 (DWebBrowserEvents2_NavigateComplete2EventHandler );
	public virtual void remove_NavigateError (DWebBrowserEvents2_NavigateErrorEventHandler );
	public virtual void remove_NewWindow (DWebBrowserEvents_NewWindowEventHandler );
	public virtual void remove_NewWindow2 (DWebBrowserEvents2_NewWindow2EventHandler );
	public virtual void remove_NewWindow3 (DWebBrowserEvents2_NewWindow3EventHandler );
	public virtual void remove_OnFullScreen (DWebBrowserEvents2_OnFullScreenEventHandler );
	public virtual void remove_OnMenuBar (DWebBrowserEvents2_OnMenuBarEventHandler );
	public virtual void remove_OnQuit (DWebBrowserEvents2_OnQuitEventHandler );
	public virtual void remove_OnStatusBar (DWebBrowserEvents2_OnStatusBarEventHandler );
	public virtual void remove_OnTheaterMode (DWebBrowserEvents2_OnTheaterModeEventHandler );
	public virtual void remove_OnToolBar (DWebBrowserEvents2_OnToolBarEventHandler );
	public virtual void remove_OnVisible (DWebBrowserEvents2_OnVisibleEventHandler );
	public virtual void remove_PrintTemplateInstantiation (DWebBrowserEvents2_PrintTemplateInstantiationEventHandler );
	public virtual void remove_PrintTemplateTeardown (DWebBrowserEvents2_PrintTemplateTeardownEventHandler );
	public virtual void remove_PrivacyImpactedStateChange (DWebBrowserEvents2_PrivacyImpactedStateChangeEventHandler );
	public virtual void remove_ProgressChange (DWebBrowserEvents2_ProgressChangeEventHandler );
	public virtual void remove_PropertyChange (DWebBrowserEvents2_PropertyChangeEventHandler );
	public virtual void remove_Quit (DWebBrowserEvents_QuitEventHandler );
	public virtual void remove_SetSecureLockIcon (DWebBrowserEvents2_SetSecureLockIconEventHandler );
	public virtual void remove_StatusTextChange (DWebBrowserEvents2_StatusTextChangeEventHandler );
	public virtual void remove_TitleChange (DWebBrowserEvents2_TitleChangeEventHandler );
	public virtual void remove_UpdatePageStatus (DWebBrowserEvents2_UpdatePageStatusEventHandler );
	public virtual void remove_WindowActivate (DWebBrowserEvents_WindowActivateEventHandler );
	public virtual void remove_WindowClosing (DWebBrowserEvents2_WindowClosingEventHandler );
	public virtual void remove_WindowMove (DWebBrowserEvents_WindowMoveEventHandler );
	public virtual void remove_WindowResize (DWebBrowserEvents_WindowResizeEventHandler );
	public virtual void remove_WindowSetHeight (DWebBrowserEvents2_WindowSetHeightEventHandler );
	public virtual void remove_WindowSetLeft (DWebBrowserEvents2_WindowSetLeftEventHandler );
	public virtual void remove_WindowSetResizable (DWebBrowserEvents2_WindowSetResizableEventHandler );
	public virtual void remove_WindowSetTop (DWebBrowserEvents2_WindowSetTopEventHandler );
	public virtual void remove_WindowSetWidth (DWebBrowserEvents2_WindowSetWidthEventHandler );
	public virtual void Refresh ();
	public virtual void Refresh2 (ref object Level);
	public virtual void ShowBrowserBar (ref object pvaClsid, ref object pvarShow, ref object pvarSize);
	public virtual void Stop ();
	public virtual string ToString ();
	
	public virtual bool AddressBar {
		get;
		set;
	}
	public virtual object Application {
		get;
	}
	public virtual bool Busy {
		get;
	}
	public virtual object Container {
		get;
	}
	public virtual object Document {
		get;
	}
	public virtual string FullName {
		get;
	}
	public virtual bool FullScreen {
		get;
		set;
	}
	public virtual int Height {
		get;
		set;
	}
	public virtual int HWND {
		get;
	}
	public virtual object IWebBrowserApp_Application {
		get;
	}
	public virtual bool IWebBrowserApp_Busy {
		get;
	}
	public virtual object IWebBrowserApp_Container {
		get;
	}
	public virtual object IWebBrowserApp_Document {
		get;
	}
	public virtual string IWebBrowserApp_FullName {
		get;
	}
	public virtual bool IWebBrowserApp_FullScreen {
		get;
		set;
	}
	public virtual int IWebBrowserApp_Height {
		get;
		set;
	}
	public virtual int IWebBrowserApp_HWND {
		get;
	}
	public virtual int IWebBrowserApp_Left {
		get;
		set;
	}
	public virtual string IWebBrowserApp_LocationName {
		get;
	}
	public virtual string IWebBrowserApp_LocationURL {
		get;
	}
	public virtual bool IWebBrowserApp_MenuBar {
		get;
		set;
	}
	public virtual string IWebBrowserApp_Name {
		get;
	}
	public virtual object IWebBrowserApp_Parent {
		get;
	}
	public virtual string IWebBrowserApp_Path {
		get;
	}
	public virtual bool IWebBrowserApp_StatusBar {
		get;
		set;
	}
	public virtual string IWebBrowserApp_StatusText {
		get;
		set;
	}
	public virtual int IWebBrowserApp_ToolBar {
		get;
		set;
	}
	public virtual int IWebBrowserApp_Top {
		get;
		set;
	}
	public virtual bool IWebBrowserApp_TopLevelContainer {
		get;
	}
	public virtual string IWebBrowserApp_Type {
		get;
	}
	public virtual bool IWebBrowserApp_Visible {
		get;
		set;
	}
	public virtual int IWebBrowserApp_Width {
		get;
		set;
	}
	public virtual int Left {
		get;
		set;
	}
	public virtual string LocationName {
		get;
	}
	public virtual string LocationURL {
		get;
	}
	public virtual bool MenuBar {
		get;
		set;
	}
	public virtual string Name {
		get;
	}
	public virtual bool Offline {
		get;
		set;
	}
	public virtual object Parent {
		get;
	}
	public virtual string Path {
		get;
	}
	public virtual tagREADYSTATE ReadyState {
		get;
	}
	public virtual bool RegisterAsBrowser {
		get;
		set;
	}
	public virtual bool RegisterAsDropTarget {
		get;
		set;
	}
	public virtual bool Resizable {
		get;
		set;
	}
	public virtual bool Silent {
		get;
		set;
	}
	public virtual bool StatusBar {
		get;
		set;
	}
	public virtual string StatusText {
		get;
		set;
	}
	public virtual bool TheaterMode {
		get;
		set;
	}
	public virtual int ToolBar {
		get;
		set;
	}
	public virtual int Top {
		get;
		set;
	}
	public virtual bool TopLevelContainer {
		get;
	}
	public virtual string Type {
		get;
	}
	public virtual bool Visible {
		get;
		set;
	}
	public virtual int Width {
		get;
		set;
	}
	
	public event DWebBrowserEvents_BeforeNavigateEventHandler BeforeNavigate;
	public event DWebBrowserEvents2_BeforeNavigate2EventHandler BeforeNavigate2;
	public event DWebBrowserEvents2_ClientToHostWindowEventHandler ClientToHostWindow;
	public event DWebBrowserEvents2_CommandStateChangeEventHandler CommandStateChange;
	public event DWebBrowserEvents2_DocumentCompleteEventHandler DocumentComplete;
	public event DWebBrowserEvents2_DownloadBeginEventHandler DownloadBegin;
	public event DWebBrowserEvents2_DownloadCompleteEventHandler DownloadComplete;
	public event DWebBrowserEvents_CommandStateChangeEventHandler DWebBrowserEvents_Event_CommandStateChange;
	public event DWebBrowserEvents_DownloadBeginEventHandler DWebBrowserEvents_Event_DownloadBegin;
	public event DWebBrowserEvents_DownloadCompleteEventHandler DWebBrowserEvents_Event_DownloadComplete;
	public event DWebBrowserEvents_ProgressChangeEventHandler DWebBrowserEvents_Event_ProgressChange;
	public event DWebBrowserEvents_PropertyChangeEventHandler DWebBrowserEvents_Event_PropertyChange;
	public event DWebBrowserEvents_QuitEventHandler DWebBrowserEvents_Event_Quit;
	public event DWebBrowserEvents_StatusTextChangeEventHandler DWebBrowserEvents_Event_StatusTextChange;
	public event DWebBrowserEvents_TitleChangeEventHandler DWebBrowserEvents_Event_TitleChange;
	public event DWebBrowserEvents2_FileDownloadEventHandler FileDownload;
	public event DWebBrowserEvents_FrameBeforeNavigateEventHandler FrameBeforeNavigate;
	public event DWebBrowserEvents_FrameNavigateCompleteEventHandler FrameNavigateComplete;
	public event DWebBrowserEvents_FrameNewWindowEventHandler FrameNewWindow;
	public event DWebBrowserEvents_NavigateCompleteEventHandler NavigateComplete;
	public event DWebBrowserEvents2_NavigateComplete2EventHandler NavigateComplete2;
	public event DWebBrowserEvents2_NavigateErrorEventHandler NavigateError;
	public event DWebBrowserEvents_NewWindowEventHandler NewWindow;
	public event DWebBrowserEvents2_NewWindow2EventHandler NewWindow2;
	public event DWebBrowserEvents2_NewWindow3EventHandler NewWindow3;
	public event DWebBrowserEvents2_OnFullScreenEventHandler OnFullScreen;
	public event DWebBrowserEvents2_OnMenuBarEventHandler OnMenuBar;
	public event DWebBrowserEvents2_OnQuitEventHandler OnQuit;
	public event DWebBrowserEvents2_OnStatusBarEventHandler OnStatusBar;
	public event DWebBrowserEvents2_OnTheaterModeEventHandler OnTheaterMode;
	public event DWebBrowserEvents2_OnToolBarEventHandler OnToolBar;
	public event DWebBrowserEvents2_OnVisibleEventHandler OnVisible;
	public event DWebBrowserEvents2_PrintTemplateInstantiationEventHandler PrintTemplateInstantiation;
	public event DWebBrowserEvents2_PrintTemplateTeardownEventHandler PrintTemplateTeardown;
	public event DWebBrowserEvents2_PrivacyImpactedStateChangeEventHandler PrivacyImpactedStateChange;
	public event DWebBrowserEvents2_ProgressChangeEventHandler ProgressChange;
	public event DWebBrowserEvents2_PropertyChangeEventHandler PropertyChange;
	public event DWebBrowserEvents2_SetSecureLockIconEventHandler SetSecureLockIcon;
	public event DWebBrowserEvents2_StatusTextChangeEventHandler StatusTextChange;
	public event DWebBrowserEvents2_TitleChangeEventHandler TitleChange;
	public event DWebBrowserEvents2_UpdatePageStatusEventHandler UpdatePageStatus;
	public event DWebBrowserEvents_WindowActivateEventHandler WindowActivate;
	public event DWebBrowserEvents2_WindowClosingEventHandler WindowClosing;
	public event DWebBrowserEvents_WindowMoveEventHandler WindowMove;
	public event DWebBrowserEvents_WindowResizeEventHandler WindowResize;
	public event DWebBrowserEvents2_WindowSetHeightEventHandler WindowSetHeight;
	public event DWebBrowserEvents2_WindowSetLeftEventHandler WindowSetLeft;
	public event DWebBrowserEvents2_WindowSetResizableEventHandler WindowSetResizable;
	public event DWebBrowserEvents2_WindowSetTopEventHandler WindowSetTop;
	public event DWebBrowserEvents2_WindowSetWidthEventHandler WindowSetWidth;
}
}
