using System;
using System.Collections.Generic;
using System.Text;

namespace Z1
{
    public class OperacjaFinansowaEventArgs : EventArgs
    {
        public decimal Kwota { get; }
        public string Opis{ get; }
        public OperacjaFinansowaEventArgs(decimal kwota, string opis) {
            this.Kwota = kwota;
            this.Opis = opis;
        }
    }
}
