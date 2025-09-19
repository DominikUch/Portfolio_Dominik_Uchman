using NUnit.Framework;
using System;
using System.Collections.Generic;
using System.Text;

namespace Z1
{
    public class RachunekFirmowy : RachunekBankowy
    {
        protected string nazwaFirmy;
        public RachunekFirmowy(string numerRachunku, string właściciel, string nazwaFirmy) : base(numerRachunku, właściciel){
            this.nazwaFirmy = nazwaFirmy;
        }

        public static explicit operator RachunekOsobisty(RachunekFirmowy rachunek){
            return new RachunekOsobisty(rachunek.NumerRachunku,rachunek.Właściciel);
        }
        public static implicit operator RachunekFirmowy(string rachunek){
            if (string.IsNullOrWhiteSpace(rachunek))
                return null;
            var parts = rachunek.Split(',', StringSplitOptions.RemoveEmptyEntries);
            if (parts.Length == 3){
                return new RachunekFirmowy(parts[0], parts[1], parts[2]);
            }
            return null;
        }

    }


}
