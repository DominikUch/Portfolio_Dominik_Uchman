using System;
using System.Collections.Generic;
using System.Text;

namespace Z1
{
    public class Dog : Animal, IMovable
    {
        public Dog(string name) : base(name){}
        public new void MakeSound() {
            Console.WriteLine("Woof!");
        }
        public void Move()
        {
            Console.WriteLine("Dog is running!");
        }

        public static implicit operator string(Dog v){
            //throw new NotImplementedException();
            return v?.Name;
        }

        public static implicit operator Dog(string v){
            {
                if (v == null) return new Dog(null);
                if (v == "") return new Dog("");
                return new Dog(v.Trim());
            }
        }
    }
}
