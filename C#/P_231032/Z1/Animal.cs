using System;
using System.Collections.Generic;
using System.Diagnostics.CodeAnalysis;
using System.Text;
using Newtonsoft.Json;
using Newtonsoft.Json.Converters;

namespace Z1
{
    public delegate void AnimalAddedEventHandler(object sender, AnimalEventArgs e);
    public abstract class Animal : IAnimal, IComparable<Animal>
    {
        [JsonProperty]
        public string Name { get; set; }
        public Animal(string name) {
            Name = name;
        }

        public override bool Equals(object obj){
            if (obj is Animal a){
                if (Name == a.Name){
                    return true;
                }
                else{
                    return Name == a.Name ? true : false;
                }
            }
            return false;
        }
        public override int GetHashCode(){
            return HashCode.Combine(Name + Name.Length);
        }



        public void MakeSound() {
            Console.WriteLine("Meow!");
        }

        //Serializacja klasy ABSTRAKCYJNEJ (i generycznej public abstract class Animal : IAnimal, IComparable<Animal>)
        public static string Serialize(Animal animal)
        {
            return JsonConvert.SerializeObject(animal, new JsonSerializerSettings { TypeNameHandling = TypeNameHandling.All });
        }

        //Deerializacja klasy ABSTRAKCYJNEJ (i generycznej public abstract class Animal : IAnimal, IComparable<Animal>)
        public static Animal Deserialize(string jsonString)
        {
            return JsonConvert.DeserializeObject<Animal>(jsonString, new JsonSerializerSettings { TypeNameHandling = TypeNameHandling.All });
        }

        public int CompareTo([AllowNull] Animal other){
            return String.Compare(Name, other.Name);
        }

        public class AnimalNameLengthComparer : IComparer<Animal>{
            public int Compare(Animal x, Animal y){
                if (x == null || y == null) throw new ArgumentNullException();
                else {
                    return x.Name.Length.CompareTo(y.Name.Length);
                }
            }
        }

    }
}
