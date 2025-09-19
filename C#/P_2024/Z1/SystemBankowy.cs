using Newtonsoft.Json;
using System;
using System.Collections.Generic;
using System.Reflection.Metadata.Ecma335;
using System.Text;
using Newtonsoft.Json;
using Newtonsoft.Json.Converters;
using System.Linq;
namespace Z1
{
    public class SystemBankowy
    {
        public List<OperacjaFinansowaEventArgs> HistoriaTranskacji = new List<OperacjaFinansowaEventArgs>();
        public List<RachunekBankowy> RachunkiBankowe = new List<RachunekBankowy>();

        public RachunekBankowy this[string s]{
            get{
                for (int i = 0; i < RachunkiBankowe.Count; i++){
                    if (RachunkiBankowe[i].NumerRachunku == s){
                        return RachunkiBankowe[i];
                    }
                }
                return null;
            }
        }
        public string Serializuj(){
            return Convert.ToString(JsonConvert.SerializeObject(RachunkiBankowe, Formatting.Indented, new JsonSerializerSettings { TypeNameHandling = TypeNameHandling.Auto }));
        }

        public List<RachunekBankowy> Deserializuj(string json){
            List<RachunekBankowy> wynik = JsonConvert.DeserializeObject<List<RachunekBankowy>>(json, new JsonSerializerSettings{ TypeNameHandling = TypeNameHandling.All});
            if (wynik != null){
                return wynik;
            }
            else{
                return new List<RachunekBankowy>();
            }
        }
        public void DodajRachunek(RachunekBankowy b){
            RachunkiBankowe.Add(b);
            b.OnOperacjaFinansowa += (sender, args) => { HistoriaTranskacji.Add(args); };
        }


        public void Przelew(RachunekBankowy z, RachunekBankowy na, decimal kwota) {
            if (!RachunkiBankowe.Contains(na) || !RachunkiBankowe.Contains(z)){
                return;
            }
            if (z.Wypłać(kwota)) {
                na.Wpłać(kwota);
            }
        }
        public void Przelew(RachunekBankowy z, string na, decimal kwota){
            var nowyNa = this[na];
            if (z == null || nowyNa == null || !RachunkiBankowe.Contains(z) || !RachunkiBankowe.Contains(nowyNa)){
                return;
            }
            Przelew(z, nowyNa, kwota);
        }

        public void Przelew(string z, string na, decimal kwota){
            Przelew(this[z], this[na], kwota);
        }

        
        public bool UsunRachunek(RachunekBankowy b) {
            if (RachunkiBankowe.Contains(b)) {
                RachunkiBankowe.Remove(b);
                return true;
            }
            return false;
        }
    }
}
