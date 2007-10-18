using System;
using System.Runtime.InteropServices;

namespace Mono.Mozilla
{	
	public delegate void CallbackDelegate();
	public delegate void GetControlSizeCallbackDelegate(ref SizeInfo sz);
	public delegate void ResizeToCallbackDelegate(Int32 width, Int32 height);
	public delegate void ShowTooltipCallbackDelegate(Int32 x, Int32 y, string tiptext);
	public delegate void StateSpecialCallbackDelegate(UInt32 flags, Int32 status);
	public delegate void StateChangeCallbackDelegate(string URI, UInt32 flags, Int32 status);
	public delegate void ProgressCallbackDelegate(Int32 currentTotalProgess, Int32 maxTotalProgress);
	public delegate void ProgressAllCallbackDelegate(string URI, Int32 currentTotalProgess, Int32 maxTotalProgress);
	public delegate void StatusChangeCallbackDelegate(Int32 status, string message);
	public delegate void SecurityChangeCallbackDelegate(UInt32 state);
	public delegate void VisibilityCallbackDelegate(bool val);
	
	//Don't have to worry about marshelling bool, PRBool seems very constant and uses 4 bit int underneath
	public delegate bool DomKeyCallbackDelegate(ModifierKeys modKey, KeyInfo keyInfo);
	public delegate bool MouseCallbackDelegate(ModifierKeys modKey, MouseInfo mouseInfo);
	public delegate bool FocusCallbackDelegate(Int32 detail);
	public delegate bool BeforeUriOpenCallackDelegate(string URI);
}
