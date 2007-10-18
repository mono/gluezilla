using System;
using System.Text;
using System.Runtime.InteropServices;

namespace Mono.Mozilla
{
	
	public sealed class MozillaInvoke
	{
		private MozillaInvoke()
		{
		}
		
		[DllImport("libmozembedcli.so")]
		public static extern void mozembed_set_profile_path(string dir, string name);
		
		[DllImport("libmozembedcli.so")]
		public static extern void mozembed_set_comp_path(string path);
		
		[DllImport("libmozembedcli.so")]
		public static extern IntPtr mozembed_create(IntPtr events);
		
		//public static extern IntPtr mozembed_create(CallbackBinder events);
		
		[DllImport("libmozembedcli.so")]
		public static extern void mozembed_init(IntPtr control, IntPtr nativeWin);
		
		[DllImport("libmozembedcli.so")]
		public static extern void mozembed_destory(IntPtr control);

		[DllImport("libmozembedcli.so")]
		public static extern void mozembed_set_chrome_mask(IntPtr control, UInt32 chromeMask);

		[DllImport("libmozembedcli.so")]
		public static extern void mozembed_apply_chrome_mask(IntPtr control);
		
		[DllImport("libmozembedcli.so")]
		public static extern void mozembed_show(IntPtr control);
		
		[DllImport("libmozembedcli.so")]
		public static extern void mozembed_hide(IntPtr control);

		[DllImport("libmozembedcli.so")]
		public static extern void mozembed_resize(IntPtr control, UInt32 width, UInt32 height);
		
		[DllImport("libmozembedcli.so")]
		public static extern SizeInfo mozembed_get_size(IntPtr control);
		
		[DllImport("libmozembedcli.so")]
		public static extern void mozembed_get_uri(IntPtr control, StringBuilder mURI);
		
		[DllImport("libmozembedcli.so")]
		public static extern void mozembed_set_uri(IntPtr control, string mURI);
		
	}
	
}
