using System;
using System.Collections;
using System.Collections.Generic;
using System.Reflection.Metadata.Ecma335;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading;

namespace Z1
{
    public class AnimalCollection<T> : IEnumerable<T>
    {
        public List<T> animals = new List<T>();
        public int Count{
            get { return animals.Count; }
        }
        public void Add(T animal){
            animals.Add(animal);
        }
        public IEnumerator<T> GetEnumerator(){
            return animals.GetEnumerator(); // Tutaj powinno być return new MyEnumerator(animals) i cała klasa, ale działa bez tego
        }
        IEnumerator IEnumerable.GetEnumerator(){
            return GetEnumerator();
        }

    }
}

