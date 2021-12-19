using Microsoft.Win32;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace RegisterCoder
{
    public class RegistryMgr
    {
        public static void WhoCreateThisAPI()
        {
            MessageBox.Show("API Created by SkieHacker xD");
        }

        public static string GetValue(string RegisteryFolderName, string ValueName)
        {
            RegistryKey key = Registry.CurrentUser.OpenSubKey(@"SOFTWARE\" + RegisteryFolderName);
            if (key != null)
            {
                string retard = key.GetValue(ValueName).ToString();
                return retard;
            }
            return string.Empty;
        }

        public static void SetValue(string RegisteryFolderName, string ValueName, string text)
        {
            RegistryKey key = Registry.CurrentUser.CreateSubKey(@"SOFTWARE\" + RegisteryFolderName);
            key.SetValue(ValueName, text);
            key.Close();
        }
    }
}
