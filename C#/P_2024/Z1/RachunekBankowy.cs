using System;
using System.Collections.Generic;
using System.Diagnostics.CodeAnalysis;
using System.Runtime.InteropServices.WindowsRuntime;
using System.Security.Cryptography.X509Certificates;
using System.Text;

namespace Z1
{
    public delegate void OperacjaFinansowaEventHandler(object? sender, OperacjaFinansowaEventArgs e);
    public abstract class RachunekBankowy : IComparable<RachunekBankowy>
    {
        public event OperacjaFinansowaEventHandler OnOperacjaFinansowa;

        protected string numerRachunku;
        protected decimal saldo;
        protected string właściciel;
        public string NumerRachunku{ get; }
        public string Właściciel { get; }

        public object Clone() {
            return MemberwiseClone();
        }

        
        public override bool Equals(object obj)
        {
            if (obj is null && this == null) return true;
            if(obj is RachunekBankowy inny){
                return NumerRachunku == inny.NumerRachunku? true : false;
            }
            if (obj is String a) {
                return String.Equals(NumerRachunku, a);
            }
            return false;
        }
        public override int GetHashCode(){
            return HashCode.Combine(NumerRachunku);
        }
        public RachunekBankowy(string numerRachunku, string właściciel) {
            NumerRachunku = numerRachunku;
            Właściciel = właściciel;
        }
        public bool Wpłać(decimal kwota)
        {
            if (kwota <= 0m){
                if (OnOperacjaFinansowa != null)
                    OnOperacjaFinansowa.Invoke(Clone(), new OperacjaFinansowaEventArgs(kwota, "Błąd: Próba wpłaty środków mniejszych bądź równych zero."));
                return false;
            }
            saldo += kwota;
            if (OnOperacjaFinansowa != null)
                OnOperacjaFinansowa.Invoke(Clone(), new OperacjaFinansowaEventArgs(kwota, "Wpłata środków"));
            return true;
        }

        public bool Wypłać(decimal kwota){
            if (kwota <= 0m || saldo - kwota < 0m){
                if (OnOperacjaFinansowa != null)
                    OnOperacjaFinansowa.Invoke(Clone(), new OperacjaFinansowaEventArgs(kwota, "Błąd: Brak wystarczających środków na rachunku."));
                return false;
            }
            saldo -= kwota;
            if (OnOperacjaFinansowa != null)
                OnOperacjaFinansowa.Invoke(Clone(), new OperacjaFinansowaEventArgs(kwota, "Wypłata środków"));
            return true;
        }


        public int CompareTo(RachunekBankowy other){
            if (other is null && this == null) return 0;
            else{
                return Właściciel.CompareTo(other.Właściciel);
            }
        }
        public class SortowanieSaldaComparer : IComparer<RachunekBankowy>{
            public int Compare( RachunekBankowy x,RachunekBankowy y){
                if (x.saldo > y.saldo){
                    return -1;
                }
                else if (x.saldo < y.saldo) {
                    return 1;
                }
                return 0;
            }
        }

    }


}
