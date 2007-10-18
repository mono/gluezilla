using System;
using System.Runtime.InteropServices;

namespace Mono.Mozilla
{
	[StructLayout (LayoutKind.Sequential)]
	public struct CallbackBinder
	{
		
		public CallbackDelegate 				EventJSStatus;
		public CallbackDelegate 				EventLinkStatus;
		public CallbackDelegate 				EventDestoryBrowser;
		public ResizeToCallbackDelegate 		EventSizeTo;
		public CallbackDelegate 				EventFocusNext;
		public CallbackDelegate 				EventFocusPrev;
		public CallbackDelegate 				EventTitleChanged;
		public ShowTooltipCallbackDelegate		EventShowTooltipWindow;
		public CallbackDelegate 				EventHideTooltipWindow;
		public CallbackDelegate 				EventStateNetStart;
		public CallbackDelegate 				EventStateNetStop;
		public StateSpecialCallbackDelegate		EventStateSpecial;
		public StateChangeCallbackDelegate		EventStateChange;
		public ProgressCallbackDelegate			EventProgress;
		public ProgressAllCallbackDelegate		EventProgressAll;
		public CallbackDelegate					EventLocationChanged;
		public StatusChangeCallbackDelegate		EventStatusChange;
		public SecurityChangeCallbackDelegate	EventSecurityChange;
		public VisibilityCallbackDelegate		EventVisibility;
		public GetControlSizeCallbackDelegate 	GetControlSize;
		public DomKeyCallbackDelegate			EventDomKeyDown;
		public DomKeyCallbackDelegate			EventDomKeyUp;
		public DomKeyCallbackDelegate			EventDomKeyPress;
		public MouseCallbackDelegate			EventMouseDown;
		public MouseCallbackDelegate			EventMouseUp;
		public MouseCallbackDelegate			EventMouseClick;
		public MouseCallbackDelegate			EventMouseDoubleClick;
		public MouseCallbackDelegate			EventMouseOver;
		public MouseCallbackDelegate			EventMouseOut;
		public FocusCallbackDelegate			EventActivate;
		public FocusCallbackDelegate			EventFocusIn;
		public FocusCallbackDelegate			EventFocusOut;
		public BeforeUriOpenCallackDelegate		EventBeforeURIOpen;
		
		public static CallbackBinder WrapIWebBrowser(IWebBrowser iwb)
		{
			CallbackBinder cb = new CallbackBinder();
			cb.GetControlSize = new GetControlSizeCallbackDelegate(iwb.GetControlSize);
			cb.EventJSStatus = new CallbackDelegate(iwb.OnJSStatus);
			cb.EventLinkStatus = new CallbackDelegate(iwb.OnLinkStatus);
			cb.EventDestoryBrowser = new CallbackDelegate(iwb.OnDestoryBrowser);
			cb.EventSizeTo = new ResizeToCallbackDelegate(iwb.OnClientSizeTo);
			cb.EventFocusNext = new CallbackDelegate(iwb.OnFocusNext);
			cb.EventFocusPrev = new CallbackDelegate(iwb.OnFocusPrev);
			cb.EventTitleChanged = new CallbackDelegate(iwb.OnTitleChanged);
			cb.EventShowTooltipWindow = new ShowTooltipCallbackDelegate(iwb.OnShowTooltipWindow);
			cb.EventHideTooltipWindow = new CallbackDelegate(iwb.OnHideTooltipWindow);
			cb.EventStateNetStart = new CallbackDelegate(iwb.OnStateNetStart);
			cb.EventStateNetStop = new CallbackDelegate(iwb.OnStateNetStop);
			cb.EventStateSpecial = new StateSpecialCallbackDelegate(iwb.OnStateSpecial);
			cb.EventStateChange =  new StateChangeCallbackDelegate(iwb.OnStateChange);
			cb.EventProgress = new ProgressCallbackDelegate(iwb.OnProgress);
			cb.EventProgressAll = new ProgressAllCallbackDelegate(iwb.OnProgressAll);
			cb.EventLocationChanged = new CallbackDelegate(iwb.OnLocationChanged);
			cb.EventStatusChange = new StatusChangeCallbackDelegate(iwb.OnStatusChange);
			cb.EventSecurityChange = new SecurityChangeCallbackDelegate(iwb.OnSecurityChange);
			cb.EventVisibility = new VisibilityCallbackDelegate(iwb.OnVisibility);
			cb.EventDomKeyDown = new DomKeyCallbackDelegate(iwb.OnClientDomKeyDown);
			cb.EventDomKeyUp = new DomKeyCallbackDelegate(iwb.OnClientDomKeyUp);
			cb.EventDomKeyPress = new DomKeyCallbackDelegate(iwb.OnClientDomKeyPress);
			cb.EventMouseDown = new MouseCallbackDelegate(iwb.OnClientMouseDown);
			cb.EventMouseUp = new MouseCallbackDelegate(iwb.OnClientMouseUp);
			cb.EventMouseClick = new MouseCallbackDelegate(iwb.OnClientMouseClick);
			cb.EventMouseDoubleClick = new MouseCallbackDelegate(iwb.OnClientMouseDoubleClick);
			cb.EventMouseOver = new MouseCallbackDelegate(iwb.OnClientMouseOver);
			cb.EventMouseOut = new MouseCallbackDelegate(iwb.OnClientMouseOut);
			cb.EventActivate = new FocusCallbackDelegate(iwb.OnClientActivate);
			cb.EventFocusIn = new FocusCallbackDelegate(iwb.OnClientFocusIn);
			cb.EventFocusOut = new FocusCallbackDelegate(iwb.OnClientFocusOut);
			cb.EventBeforeURIOpen = new BeforeUriOpenCallackDelegate(iwb.OnBeforeURIOpen);
			return cb;
		}
	}
}
