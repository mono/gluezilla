using System;
using SHDocVw;

namespace AxSHDocVw
{

public class AxWebBrowser : System.Windows.Forms.AxHost, System.ComponentModel.IComponent, System.ComponentModel.ICustomTypeDescriptor, IDisposable, System.ComponentModel.ISupportInitialize, System.ComponentModel.ISynchronizeInvoke, System.Windows.Forms.IWin32Window {
	
	public AxWebBrowser ();
	
	protected void AccessibilityNotifyClients (System.Windows.Forms.AccessibleEvents accEvent, int childID);
	protected override void AttachInterfaces ();
	public void BeginInit ();
	public IAsyncResult BeginInvoke (Delegate method);
	public IAsyncResult BeginInvoke (Delegate method, object [] args);
	public void BringToFront ();
	public virtual void ClientToWindow (ref int pcx, ref int pcy);
	public bool Contains (System.Windows.Forms.Control ctl);
	protected virtual System.Windows.Forms.AccessibleObject CreateAccessibilityInstance ();
	public void CreateControl ();
	protected virtual Control.System.Windows.Forms.ControlCollection CreateControlsInstance ();
	public System.Drawing.Graphics CreateGraphics ();
	protected override void CreateHandle ();
	public virtual System.Runtime.Remoting.ObjRef CreateObjRef (Type type);
	protected override void CreateSink ();
	public virtual void CtlRefresh ();
	protected virtual void DefWndProc (ref System.Windows.Forms.Message m);
	protected override void DestroyHandle ();
	protected override void DetachSink ();
	public void Dispose ();
	protected override void Dispose (bool disposing);
	public System.Windows.Forms.DragDropEffects DoDragDrop (object data, System.Windows.Forms.DragDropEffects allowedEffects);
	public void DoVerb (int verb);
	public void EndInit ();
	public object EndInvoke (IAsyncResult async_result);
	public virtual bool Equals (object o);
	public virtual void ExecWB (SHDocVw.OLECMDID cmdID, SHDocVw.OLECMDEXECOPT cmdexecopt, ref object pvaIn, ref object pvaOut);
	protected override void Finalize ();
	public System.Windows.Forms.Form FindForm ();
	public bool Focus ();
	public System.Windows.Forms.Control GetChildAtPoint (System.Drawing.Point pt);
	public System.Windows.Forms.IContainerControl GetContainerControl ();
	public virtual int GetHashCode ();
	public virtual object GetLifetimeService ();
	public System.Windows.Forms.Control GetNextControl (System.Windows.Forms.Control ctl, bool forward);
	public object GetOcx ();
	public virtual object GetProperty (string property);
	protected virtual object GetService (Type service);
	protected bool GetStyle (System.Windows.Forms.ControlStyles flag);
	protected bool GetTopLevel ();
	public Type GetType ();
	public virtual void GoBack ();
	public virtual void GoForward ();
	public virtual void GoHome ();
	public virtual void GoSearch ();
	public bool HasPropertyPages ();
	public void Hide ();
	public virtual object InitializeLifetimeService ();
	protected virtual void InitLayout ();
	public void Invalidate ();
	public void Invalidate (bool invalidateChildren);
	public void Invalidate (System.Drawing.Rectangle rc);
	public void Invalidate (System.Drawing.Rectangle rc, bool invalidateChildren);
	public void Invalidate (System.Drawing.Region region);
	public void Invalidate (System.Drawing.Region region, bool invalidateChildren);
	public object Invoke (Delegate method);
	public object Invoke (Delegate method, object [] args);
	public void InvokeEditMode ();
	protected void InvokeGotFocus (System.Windows.Forms.Control toInvoke, EventArgs e);
	protected void InvokeLostFocus (System.Windows.Forms.Control toInvoke, EventArgs e);
	protected void InvokeOnClick (System.Windows.Forms.Control toInvoke, EventArgs e);
	protected void InvokePaint (System.Windows.Forms.Control toInvoke, System.Windows.Forms.PaintEventArgs e);
	protected void InvokePaintBackground (System.Windows.Forms.Control toInvoke, System.Windows.Forms.PaintEventArgs e);
	protected override bool IsInputChar (char charCode);
	protected virtual bool IsInputKey (System.Windows.Forms.Keys keyData);
	public void MakeDirty ();
	protected object MemberwiseClone ();
	public virtual void Navigate (string uRL, ref object flags, ref object targetFrameName, ref object postData, ref object headers);
	public virtual void Navigate2 (ref object uRL, ref object flags, ref object targetFrameName, ref object postData, ref object headers);
	protected virtual void NotifyInvalidate (System.Drawing.Rectangle invalidatedArea);
	protected override void OnBackColorChanged (EventArgs e);
	protected virtual void OnBackgroundImageChanged (EventArgs e);
	protected virtual void OnBindingContextChanged (EventArgs e);
	protected virtual void OnCausesValidationChanged (EventArgs e);
	protected virtual void OnChangeUICues (System.Windows.Forms.UICuesEventArgs e);
	protected virtual void OnClick (EventArgs e);
	protected virtual void OnContextMenuChanged (EventArgs e);
	protected virtual void OnControlAdded (System.Windows.Forms.ControlEventArgs e);
	protected virtual void OnControlRemoved (System.Windows.Forms.ControlEventArgs e);
	protected virtual void OnCreateControl ();
	protected virtual void OnCursorChanged (EventArgs e);
	protected virtual void OnDockChanged (EventArgs e);
	protected virtual void OnDoubleClick (EventArgs e);
	protected virtual void OnDragDrop (System.Windows.Forms.DragEventArgs drgevent);
	protected virtual void OnDragEnter (System.Windows.Forms.DragEventArgs drgevent);
	protected virtual void OnDragLeave (EventArgs e);
	protected virtual void OnDragOver (System.Windows.Forms.DragEventArgs drgevent);
	protected virtual void OnEnabledChanged (EventArgs e);
	protected virtual void OnEnter (EventArgs e);
	protected override void OnFontChanged (EventArgs e);
	protected override void OnForeColorChanged (EventArgs e);
	protected virtual void OnGiveFeedback (System.Windows.Forms.GiveFeedbackEventArgs gfbevent);
	protected virtual void OnGotFocus (EventArgs e);
	protected override void OnHandleCreated (EventArgs e);
	protected virtual void OnHandleDestroyed (EventArgs e);
	protected virtual void OnHelpRequested (System.Windows.Forms.HelpEventArgs hevent);
	protected virtual void OnImeModeChanged (EventArgs e);
	protected virtual void OnInPlaceActive ();
	protected virtual void OnInvalidated (System.Windows.Forms.InvalidateEventArgs e);
	protected virtual void OnKeyDown (System.Windows.Forms.KeyEventArgs e);
	protected virtual void OnKeyPress (System.Windows.Forms.KeyPressEventArgs e);
	protected virtual void OnKeyUp (System.Windows.Forms.KeyEventArgs e);
	protected virtual void OnLayout (System.Windows.Forms.LayoutEventArgs levent);
	protected virtual void OnLeave (EventArgs e);
	protected virtual void OnLocationChanged (EventArgs e);
	protected override void OnLostFocus (EventArgs e);
	protected virtual void OnMouseDown (System.Windows.Forms.MouseEventArgs e);
	protected virtual void OnMouseEnter (EventArgs e);
	protected virtual void OnMouseHover (EventArgs e);
	protected virtual void OnMouseLeave (EventArgs e);
	protected virtual void OnMouseMove (System.Windows.Forms.MouseEventArgs e);
	protected virtual void OnMouseUp (System.Windows.Forms.MouseEventArgs e);
	protected virtual void OnMouseWheel (System.Windows.Forms.MouseEventArgs e);
	protected virtual void OnMove (EventArgs e);
	protected virtual void OnNotifyMessage (System.Windows.Forms.Message m);
	protected virtual void OnPaint (System.Windows.Forms.PaintEventArgs e);
	protected virtual void OnPaintBackground (System.Windows.Forms.PaintEventArgs pevent);
	protected virtual void OnParentBackColorChanged (EventArgs e);
	protected virtual void OnParentBackgroundImageChanged (EventArgs e);
	protected virtual void OnParentBindingContextChanged (EventArgs e);
	protected virtual void OnParentChanged (EventArgs e);
	protected virtual void OnParentEnabledChanged (EventArgs e);
	protected virtual void OnParentFontChanged (EventArgs e);
	protected virtual void OnParentForeColorChanged (EventArgs e);
	protected virtual void OnParentRightToLeftChanged (EventArgs e);
	protected virtual void OnParentVisibleChanged (EventArgs e);
	protected virtual void OnQueryContinueDrag (System.Windows.Forms.QueryContinueDragEventArgs e);
	protected virtual void OnResize (EventArgs e);
	protected virtual void OnRightToLeftChanged (EventArgs e);
	protected virtual void OnSizeChanged (EventArgs e);
	protected virtual void OnStyleChanged (EventArgs e);
	protected virtual void OnSystemColorsChanged (EventArgs e);
	protected virtual void OnTabIndexChanged (EventArgs e);
	protected virtual void OnTabStopChanged (EventArgs e);
	protected virtual void OnTextChanged (EventArgs e);
	protected virtual void OnValidated (EventArgs e);
	protected virtual void OnValidating (System.ComponentModel.CancelEventArgs e);
	protected virtual void OnVisibleChanged (EventArgs e);
	public void PerformLayout ();
	public void PerformLayout (System.Windows.Forms.Control affectedControl, string affectedProperty);
	public System.Drawing.Point PointToClient (System.Drawing.Point p);
	public System.Drawing.Point PointToScreen (System.Drawing.Point p);
	public override bool PreProcessMessage (ref System.Windows.Forms.Message msg);
	protected virtual bool ProcessCmdKey (ref System.Windows.Forms.Message msg, System.Windows.Forms.Keys keyData);
	protected virtual bool ProcessDialogChar (char charCode);
	protected override bool ProcessDialogKey (System.Windows.Forms.Keys keyData);
	protected virtual bool ProcessKeyEventArgs (ref System.Windows.Forms.Message msg);
	virtual bool ProcessKeyMessage (ref System.Windows.Forms.Message msg);
	protected virtual bool ProcessKeyPreview (ref System.Windows.Forms.Message msg);
	protected override bool ProcessMnemonic (char charCode);
	protected bool PropsValid ();
	public virtual void PutProperty (string property, object vtValue);
	public virtual SHDocVw.OLECMDF QueryStatusWB (SHDocVw.OLECMDID cmdID);
	public virtual void Quit ();
	protected void RaiseDragEvent (object key, System.Windows.Forms.DragEventArgs e);
	protected void RaiseKeyEvent (object key, System.Windows.Forms.KeyEventArgs e);
	protected void RaiseMouseEvent (object key, System.Windows.Forms.MouseEventArgs e);
	protected void RaiseOnMouseDown (short button, short shift, int x, int y);
	protected void RaiseOnMouseDown (short button, short shift, float x, float y);
	protected void RaiseOnMouseDown (object o1, object o2, object o3, object o4);
	protected void RaiseOnMouseMove (short button, short shift, int x, int y);
	protected void RaiseOnMouseMove (short button, short shift, float x, float y);
	protected void RaiseOnMouseMove (object o1, object o2, object o3, object o4);
	protected void RaiseOnMouseUp (short button, short shift, int x, int y);
	protected void RaiseOnMouseUp (short button, short shift, float x, float y);
	protected void RaiseOnMouseUp (object o1, object o2, object o3, object o4);
	protected void RaisePaintEvent (object key, System.Windows.Forms.PaintEventArgs e);
	protected void RecreateHandle ();
	public System.Drawing.Rectangle RectangleToClient (System.Drawing.Rectangle r);
	public System.Drawing.Rectangle RectangleToScreen (System.Drawing.Rectangle r);
	public virtual void Refresh ();
	public virtual void Refresh2 (ref object level);
	public virtual void ResetBackColor ();
	public void ResetBindings ();
	public virtual void ResetCursor ();
	public virtual void ResetFont ();
	public virtual void ResetForeColor ();
	public void ResetImeMode ();
	protected void ResetMouseEventArgs ();
	public virtual void ResetRightToLeft ();
	public virtual void ResetText ();
	public void ResumeLayout ();
	public void ResumeLayout (bool performLayout);
	protected System.Drawing.ContentAlignment RtlTranslateAlignment (System.Drawing.ContentAlignment align);
	protected System.Windows.Forms.HorizontalAlignment RtlTranslateAlignment (System.Windows.Forms.HorizontalAlignment align);
	protected System.Windows.Forms.LeftRightAlignment RtlTranslateAlignment (System.Windows.Forms.LeftRightAlignment align);
	protected System.Drawing.ContentAlignment RtlTranslateContent (System.Drawing.ContentAlignment align);
	protected System.Windows.Forms.HorizontalAlignment RtlTranslateHorizontal (System.Windows.Forms.HorizontalAlignment align);
	protected System.Windows.Forms.LeftRightAlignment RtlTranslateLeftRight (System.Windows.Forms.LeftRightAlignment align);
	public void Scale (float ratio);
	public void Scale (float dx, float dy);
	protected virtual void ScaleCore (float dx, float dy);
	public void Select ();
	protected virtual void Select (bool directed, bool forward);
	public bool SelectNextControl (System.Windows.Forms.Control ctl, bool forward, bool tabStopOnly, bool nested, bool wrap);
	public void SendToBack ();
	protected void SetAboutBoxDelegate (AxHost.System.Windows.Forms.AboutBoxDelegate d);
	public void SetBounds (int x, int y, int width, int height);
	public void SetBounds (int x, int y, int width, int height, System.Windows.Forms.BoundsSpecified specified);
	protected override void SetBoundsCore (int x, int y, int width, int height, System.Windows.Forms.BoundsSpecified specified);
	protected virtual void SetClientSizeCore (int x, int y);
	protected void SetStyle (System.Windows.Forms.ControlStyles flag, bool value);
	protected void SetTopLevel (bool value);
	protected override void SetVisibleCore (bool value);
	public void Show ();
	public void ShowAboutBox ();
	public virtual void ShowBrowserBar (ref object pvaClsid, ref object pvarShow, ref object pvarSize);
	public void ShowPropertyPages ();
	public void ShowPropertyPages (System.Windows.Forms.Control control);
	public virtual void Stop ();
	public void SuspendLayout ();
	System.ComponentModel.AttributeCollection System.ComponentModel.ICustomTypeDescriptor.GetAttributes ();
	string System.ComponentModel.ICustomTypeDescriptor.GetClassName ();
	string System.ComponentModel.ICustomTypeDescriptor.GetComponentName ();
	System.ComponentModel.TypeConverter System.ComponentModel.ICustomTypeDescriptor.GetConverter ();
	System.ComponentModel.EventDescriptor System.ComponentModel.ICustomTypeDescriptor.GetDefaultEvent ();
	System.ComponentModel.PropertyDescriptor System.ComponentModel.ICustomTypeDescriptor.GetDefaultProperty ();
	object System.ComponentModel.ICustomTypeDescriptor.GetEditor (Type editorBaseType);
	System.ComponentModel.EventDescriptorCollection System.ComponentModel.ICustomTypeDescriptor.GetEvents ();
	System.ComponentModel.EventDescriptorCollection System.ComponentModel.ICustomTypeDescriptor.GetEvents (Attribute [] attributes);
	System.ComponentModel.PropertyDescriptorCollection System.ComponentModel.ICustomTypeDescriptor.GetProperties ();
	System.ComponentModel.PropertyDescriptorCollection System.ComponentModel.ICustomTypeDescriptor.GetProperties (Attribute [] attributes);
	object System.ComponentModel.ICustomTypeDescriptor.GetPropertyOwner (System.ComponentModel.PropertyDescriptor pd);
	public override string ToString ();
	public void Update ();
	protected void UpdateBounds ();
	protected void UpdateBounds (int x, int y, int width, int height);
	protected void UpdateBounds (int x, int y, int width, int height, int clientWidth, int clientHeight);
	protected void UpdateStyles ();
	protected void UpdateZOrder ();
	protected override void WndProc (ref System.Windows.Forms.Message m);
	
	public System.Windows.Forms.AccessibleObject AccessibilityObject {
		get;
	}
	public string AccessibleDefaultActionDescription {
		get;
		set;
	}
	public string AccessibleDescription {
		get;
		set;
	}
	public string AccessibleName {
		get;
		set;
	}
	public System.Windows.Forms.AccessibleRole AccessibleRole {
		get;
		set;
	}
	public virtual bool AddressBar {
		get;
		set;
	}
	public virtual bool AllowDrop {
		get;
		set;
	}
	public virtual System.Windows.Forms.AnchorStyles Anchor {
		get;
		set;
	}
	public virtual object Application {
		get;
	}
	public override System.Drawing.Color BackColor {
		get;
		set;
	}
	public override System.Drawing.Image BackgroundImage {
		get;
		set;
	}
	public virtual System.Windows.Forms.BindingContext BindingContext {
		get;
		set;
	}
	public int Bottom {
		get;
	}
	public System.Drawing.Rectangle Bounds {
		get;
		set;
	}
	public virtual bool Busy {
		get;
	}
	public bool CanFocus {
		get;
	}
	public bool CanSelect {
		get;
	}
	public bool Capture {
		get;
		set;
	}
	public bool CausesValidation {
		get;
		set;
	}
	public System.Drawing.Rectangle ClientRectangle {
		get;
	}
	public System.Drawing.Size ClientSize {
		get;
		set;
	}
	public string CompanyName {
		get;
	}
	public System.ComponentModel.IContainer Container {
		get;
	}
	public System.Windows.Forms.ContainerControl ContainingControl {
		get;
		set;
	}
	public bool ContainsFocus {
		get;
	}
	public override System.Windows.Forms.ContextMenu ContextMenu {
		get;
		set;
	}
	public Control.System.Windows.Forms.ControlCollection Controls {
		get;
	}
	public bool Created {
		get;
	}
	protected override System.Windows.Forms.CreateParams CreateParams {
		get;
	}
	public virtual object CtlContainer {
		get;
	}
	public virtual int CtlHeight {
		get;
		set;
	}
	public virtual int CtlLeft {
		get;
		set;
	}
	public virtual object CtlParent {
		get;
	}
	public virtual int CtlTop {
		get;
		set;
	}
	public virtual bool CtlVisible {
		get;
		set;
	}
	public virtual int CtlWidth {
		get;
		set;
	}
	public override System.Windows.Forms.Cursor Cursor {
		get;
		set;
	}
	public System.Windows.Forms.ControlBindingsCollection DataBindings {
		get;
	}
	protected virtual System.Windows.Forms.ImeMode DefaultImeMode {
		get;
	}
	protected override System.Drawing.Size DefaultSize {
		get;
	}
	protected bool DesignMode {
		get;
	}
	public virtual System.Drawing.Rectangle DisplayRectangle {
		get;
	}
	public bool Disposing {
		get;
	}
	public virtual System.Windows.Forms.DockStyle Dock {
		get;
		set;
	}
	public virtual object Document {
		get;
	}
	public bool EditMode {
		get;
	}
	public bool Enabled {
		get;
		set;
	}
	public virtual bool Enabled {
		get;
		set;
	}
	protected System.ComponentModel.EventHandlerList Events {
		get;
	}
	public virtual bool Focused {
		get;
	}
	public override System.Drawing.Font Font {
		get;
		set;
	}
	protected int FontHeight {
		get;
		set;
	}
	public override System.Drawing.Color ForeColor {
		get;
		set;
	}
	public virtual string FullName {
		get;
	}
	public virtual bool FullScreen {
		get;
		set;
	}
	public IntPtr Handle {
		get;
	}
	public bool HasAboutBox {
		get;
	}
	public bool HasChildren {
		get;
	}
	public int Height {
		get;
		set;
	}
	public virtual int HWND {
		get;
	}
	public System.Windows.Forms.ImeMode ImeMode {
		get;
		set;
	}
	public bool InvokeRequired {
		get;
	}
	public bool IsAccessible {
		get;
		set;
	}
	public bool IsDisposed {
		get;
	}
	public bool IsHandleCreated {
		get;
	}
	public int Left {
		get;
		set;
	}
	public System.Drawing.Point Location {
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
	public string Name {
		get;
		set;
	}
	public virtual string Name {
		get;
	}
	public AxHost.System.Windows.Forms.State OcxState {
		get;
		set;
	}
	public virtual bool Offline {
		get;
		set;
	}
	public System.Windows.Forms.Control Parent {
		get;
		set;
	}
	public virtual string Path {
		get;
	}
	public string ProductName {
		get;
	}
	public string ProductVersion {
		get;
	}
	public virtual SHDocVw.tagREADYSTATE ReadyState {
		get;
	}
	public bool RecreatingHandle {
		get;
	}
	public System.Drawing.Region Region {
		get;
		set;
	}
	public virtual bool RegisterAsBrowser {
		get;
		set;
	}
	public virtual bool RegisterAsDropTarget {
		get;
		set;
	}
	protected bool RenderRightToLeft {
		get;
	}
	public virtual bool Resizable {
		get;
		set;
	}
	protected bool ResizeRedraw {
		get;
		set;
	}
	public int Right {
		get;
	}
	public virtual System.Windows.Forms.RightToLeft RightToLeft {
		get;
		set;
	}
	public virtual bool RightToLeft {
		get;
		set;
	}
	protected virtual bool ShowFocusCues {
		get;
	}
	protected bool ShowKeyboardCues {
		get;
	}
	public virtual bool Silent {
		get;
		set;
	}
	public override System.ComponentModel.ISite Site {
		set;
	}
	public System.Drawing.Size Size {
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
	public int TabIndex {
		get;
		set;
	}
	public bool TabStop {
		get;
		set;
	}
	public object Tag {
		get;
		set;
	}
	public override string Text {
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
	public int Top {
		get;
		set;
	}
	public virtual bool TopLevelContainer {
		get;
	}
	public System.Windows.Forms.Control TopLevelControl {
		get;
	}
	public virtual string Type {
		get;
	}
	public bool Visible {
		get;
		set;
	}
	public int Width {
		get;
		set;
	}
	public System.Windows.Forms.IWindowTarget WindowTarget {
		get;
		set;
	}
	
	public event EventHandler BackColorChanged;
	public event EventHandler BackColorChanged;
	public event EventHandler BackgroundImageChanged;
	public event EventHandler BackgroundImageChanged;
	public event DWebBrowserEvents2_BeforeNavigate2EventHandler BeforeNavigate2;
	public event EventHandler BindingContextChanged;
	public event EventHandler BindingContextChanged;
	public event EventHandler CausesValidationChanged;
	public event System.Windows.Forms.UICuesEventHandler ChangeUICues;
	public event System.Windows.Forms.UICuesEventHandler ChangeUICues;
	public event EventHandler Click;
	public event EventHandler Click;
	public event DWebBrowserEvents2_ClientToHostWindowEventHandler ClientToHostWindow;
	public event DWebBrowserEvents2_CommandStateChangeEventHandler CommandStateChange;
	public event EventHandler ContextMenuChanged;
	public event EventHandler ContextMenuChanged;
	public event System.Windows.Forms.ControlEventHandler ControlAdded;
	public event System.Windows.Forms.ControlEventHandler ControlRemoved;
	public event EventHandler CursorChanged;
	public event EventHandler CursorChanged;
	public event EventHandler Disposed;
	public event EventHandler DockChanged;
	public event DWebBrowserEvents2_DocumentCompleteEventHandler DocumentComplete;
	public event EventHandler DoubleClick;
	public event EventHandler DoubleClick;
	public event EventHandler DownloadBegin;
	public event EventHandler DownloadComplete;
	public event System.Windows.Forms.DragEventHandler DragDrop;
	public event System.Windows.Forms.DragEventHandler DragDrop;
	public event System.Windows.Forms.DragEventHandler DragEnter;
	public event System.Windows.Forms.DragEventHandler DragEnter;
	public event EventHandler DragLeave;
	public event EventHandler DragLeave;
	public event System.Windows.Forms.DragEventHandler DragOver;
	public event System.Windows.Forms.DragEventHandler DragOver;
	public event EventHandler EnabledChanged;
	public event EventHandler EnabledChanged;
	public event EventHandler Enter;
	public event DWebBrowserEvents2_FileDownloadEventHandler FileDownload;
	public event EventHandler FontChanged;
	public event EventHandler FontChanged;
	public event EventHandler ForeColorChanged;
	public event EventHandler ForeColorChanged;
	public event System.Windows.Forms.GiveFeedbackEventHandler GiveFeedback;
	public event System.Windows.Forms.GiveFeedbackEventHandler GiveFeedback;
	public event EventHandler GotFocus;
	public event EventHandler HandleCreated;
	public event EventHandler HandleDestroyed;
	public event System.Windows.Forms.HelpEventHandler HelpRequested;
	public event System.Windows.Forms.HelpEventHandler HelpRequested;
	public event EventHandler ImeModeChanged;
	public event EventHandler ImeModeChanged;
	public event System.Windows.Forms.InvalidateEventHandler Invalidated;
	public event System.Windows.Forms.KeyEventHandler KeyDown;
	public event System.Windows.Forms.KeyEventHandler KeyDown;
	public event System.Windows.Forms.KeyPressEventHandler KeyPress;
	public event System.Windows.Forms.KeyPressEventHandler KeyPress;
	public event System.Windows.Forms.KeyEventHandler KeyUp;
	public event System.Windows.Forms.KeyEventHandler KeyUp;
	public event System.Windows.Forms.LayoutEventHandler Layout;
	public event System.Windows.Forms.LayoutEventHandler Layout;
	public event EventHandler Leave;
	public event EventHandler LocationChanged;
	public event EventHandler LostFocus;
	public event System.Windows.Forms.MouseEventHandler MouseDown;
	public event System.Windows.Forms.MouseEventHandler MouseDown;
	public event EventHandler MouseEnter;
	public event EventHandler MouseEnter;
	public event EventHandler MouseHover;
	public event EventHandler MouseHover;
	public event EventHandler MouseLeave;
	public event EventHandler MouseLeave;
	public event System.Windows.Forms.MouseEventHandler MouseMove;
	public event System.Windows.Forms.MouseEventHandler MouseMove;
	public event System.Windows.Forms.MouseEventHandler MouseUp;
	public event System.Windows.Forms.MouseEventHandler MouseUp;
	public event System.Windows.Forms.MouseEventHandler MouseWheel;
	public event System.Windows.Forms.MouseEventHandler MouseWheel;
	public event EventHandler Move;
	public event DWebBrowserEvents2_NavigateComplete2EventHandler NavigateComplete2;
	public event DWebBrowserEvents2_NavigateErrorEventHandler NavigateError;
	public event DWebBrowserEvents2_NewWindow2EventHandler NewWindow2;
	public event DWebBrowserEvents2_NewWindow3EventHandler NewWindow3;
	public event DWebBrowserEvents2_OnFullScreenEventHandler OnFullScreen;
	public event DWebBrowserEvents2_OnMenuBarEventHandler OnMenuBar;
	public event EventHandler OnQuit;
	public event DWebBrowserEvents2_OnStatusBarEventHandler OnStatusBar;
	public event DWebBrowserEvents2_OnTheaterModeEventHandler OnTheaterMode;
	public event DWebBrowserEvents2_OnToolBarEventHandler OnToolBar;
	public event DWebBrowserEvents2_OnVisibleEventHandler OnVisible;
	public event System.Windows.Forms.PaintEventHandler Paint;
	public event System.Windows.Forms.PaintEventHandler Paint;
	public event EventHandler ParentChanged;
	public event DWebBrowserEvents2_PrintTemplateInstantiationEventHandler PrintTemplateInstantiation;
	public event DWebBrowserEvents2_PrintTemplateTeardownEventHandler PrintTemplateTeardown;
	public event DWebBrowserEvents2_PrivacyImpactedStateChangeEventHandler PrivacyImpactedStateChange;
	public event DWebBrowserEvents2_ProgressChangeEventHandler ProgressChange;
	public event DWebBrowserEvents2_PropertyChangeEventHandler PropertyChange;
	public event System.Windows.Forms.QueryAccessibilityHelpEventHandler QueryAccessibilityHelp;
	public event System.Windows.Forms.QueryAccessibilityHelpEventHandler QueryAccessibilityHelp;
	public event System.Windows.Forms.QueryContinueDragEventHandler QueryContinueDrag;
	public event System.Windows.Forms.QueryContinueDragEventHandler QueryContinueDrag;
	public event EventHandler Resize;
	public event EventHandler RightToLeftChanged;
	public event EventHandler RightToLeftChanged;
	public event DWebBrowserEvents2_SetSecureLockIconEventHandler SetSecureLockIcon;
	public event EventHandler SizeChanged;
	public event DWebBrowserEvents2_StatusTextChangeEventHandler StatusTextChange;
	public event EventHandler StyleChanged;
	public event EventHandler StyleChanged;
	public event EventHandler SystemColorsChanged;
	public event EventHandler TabIndexChanged;
	public event EventHandler TabIndexChanged;
	public event EventHandler TabStopChanged;
	public event EventHandler TabStopChanged;
	public event EventHandler TextChanged;
	public event EventHandler TextChanged;
	public event DWebBrowserEvents2_TitleChangeEventHandler TitleChange;
	public event DWebBrowserEvents2_UpdatePageStatusEventHandler UpdatePageStatus;
	public event EventHandler Validated;
	public event System.ComponentModel.CancelEventHandler Validating;
	public event EventHandler VisibleChanged;
	public event DWebBrowserEvents2_WindowClosingEventHandler WindowClosing;
	public event DWebBrowserEvents2_WindowSetHeightEventHandler WindowSetHeight;
	public event DWebBrowserEvents2_WindowSetLeftEventHandler WindowSetLeft;
	public event DWebBrowserEvents2_WindowSetResizableEventHandler WindowSetResizable;
	public event DWebBrowserEvents2_WindowSetTopEventHandler WindowSetTop;
	public event DWebBrowserEvents2_WindowSetWidthEventHandler WindowSetWidth;
}
}
