using System;
using System.Runtime.InteropServices;

namespace Mono.Mozilla
{
	[StructLayout (LayoutKind.Sequential)]
	public struct SizeInfo
	{
		public UInt32 width;
		public UInt32 height;
	}
	
	[StructLayout (LayoutKind.Sequential)]
	public struct ModifierKeys
	{
		public Int32 altKey;
		public Int32 ctrlKey;
		public Int32 metaKey;
		public Int32 shiftKey;
	}
	
	[StructLayout (LayoutKind.Sequential)]
	public struct MouseInfo
	{
		public UInt16 button;
		public Int32 clientX;
		public Int32 clientY;
		public Int32 screenX;
		public Int32 screenY;
	}

	[StructLayout (LayoutKind.Sequential)]
	public struct KeyInfo
	{
		public UInt32 charCode;
		public UInt32 keyCode;
	}
	
}
