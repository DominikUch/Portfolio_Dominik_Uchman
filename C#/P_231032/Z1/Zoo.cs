using System;
using System.Collections.Generic;
using System.Runtime.CompilerServices;
using System.Runtime.Intrinsics.X86;
using System.Text;

namespace Z1
{
    public class Zoo
    {
        protected List<Animal> animals = new List<Animal>();
        public List<Animal> Animals
        {
            get { return animals; }
        }
        public Animal this[int index]{
            get{
                if (index < 0 || index >= animals.Count) throw new IndexOutOfRangeException();
                return animals[index];
            }
            set{
                if (index < 0 || index >= animals.Count) throw new IndexOutOfRangeException();
                animals[index] = value;
            }
        }
        public Animal this[string name]{
            get{
                foreach (Animal animal in animals){
                    if (animal.Name == name){
                        return animal;
                    }
                }
                throw new Exception(message:$"Animal with name '{name}' not found.");
            }
        }

        [Obsolete("Use AddAnimal method instead.")]
        public void Add(Animal animal) {
            animals.Add(animal);
        }
        public void AddAnimal(Animal animal) {
            if (!animals.Contains(animal)) {
                animals.Add(animal);
            }
            OnAnimalAdded(new AnimalEventArgs(animal));
        }

        public event AnimalAddedEventHandler AnimalAdded;
        protected void OnAnimalAdded(AnimalEventArgs e) {
            AnimalAdded?.Invoke(this, e);
        }
    }
}
