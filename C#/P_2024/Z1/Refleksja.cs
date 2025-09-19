using System;
using System.Collections.Generic;
using System.Reflection;
using System.Text;

namespace Z1
{
    public static class Refleksja
    {
        public static string OdczytajPolePrywatne(RachunekFirmowy rachunekFimrowy) {
            if (rachunekFimrowy == null)
                throw new ArgumentNullException();

            StringBuilder sb = new StringBuilder("");
            var field = rachunekFimrowy.GetType().GetField("nazwaFirmy", BindingFlags.NonPublic | BindingFlags.Instance);
            if (field == null){
                throw new Exception();
            }
            else {
                if (field.GetValue(rachunekFimrowy) == null) {
                    return null;
                }
                sb.Append(field.GetValue(rachunekFimrowy));
            }
            return sb.ToString();
        }
    }
}
