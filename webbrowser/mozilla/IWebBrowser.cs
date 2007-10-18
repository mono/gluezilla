
using System;
using System.Runtime.InteropServices;

namespace Mono.Mozilla
{	
	public interface IWebBrowser
	{
		void GetControlSize(ref SizeInfo sz);
		void OnJSStatus();
		void OnLinkStatus();
		void OnDestoryBrowser();
		void OnClientSizeTo(Int32 width, Int32 height);
		void OnFocusNext();
		void OnFocusPrev();
		void OnTitleChanged();
		void OnShowTooltipWindow(Int32 x, Int32 y, string tiptext);
		void OnHideTooltipWindow();
		void OnStateNetStart();
		void OnStateNetStop();
		void OnStateSpecial(UInt32 stateFlags, Int32 status);
		void OnStateChange(string URI, UInt32 stateFlags, Int32 status);
		void OnProgress(Int32 currentTotalProgress, Int32 maxTotalProgress);
		void OnProgressAll(string URI, Int32 currentTotalProgress, Int32 maxTotalProgress);
		void OnLocationChanged();
		void OnStatusChange(Int32 status, string message);
		void OnSecurityChange(UInt32 state);
		void OnVisibility(bool val);

		//Don't have to worry about marshelling bool, PRBool seems very constant and uses 4 bit int underneath
		bool OnClientDomKeyDown (ModifierKeys modKey, KeyInfo keyInfo);
		bool OnClientDomKeyUp (ModifierKeys modKey, KeyInfo keyInfo);
		bool OnClientDomKeyPress (ModifierKeys modKey, KeyInfo keyInfo);
		bool OnClientMouseDown (ModifierKeys aModKey, MouseInfo aMouseInfo);
		bool OnClientMouseUp (ModifierKeys aModKey, MouseInfo aMouseInfo);
		bool OnClientMouseClick (ModifierKeys aModKey, MouseInfo aMouseInfo);
		bool OnClientMouseDoubleClick (ModifierKeys aModKey, MouseInfo aMouseInfo);
		bool OnClientMouseOver (ModifierKeys aModKey, MouseInfo aMouseInfo);
		bool OnClientMouseOut (ModifierKeys aModKey, MouseInfo aMouseInfo);
		bool OnClientActivate (Int32 detail);
		
		// TODO: These two may not fire correctly in Firefox 1.0.x
		bool OnClientFocusIn (Int32 detial);
		bool OnClientFocusOut (Int32 detial);
		
		bool OnBeforeURIOpen (string URL);
	}
}
