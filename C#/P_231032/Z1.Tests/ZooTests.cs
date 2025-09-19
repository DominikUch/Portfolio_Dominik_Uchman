using NUnit.Framework;
using System;
using System.Collections.Generic;
using System.Text;
using Z1;

namespace Z1.Tests
{
    
    [TestFixture]
    public class ZooTests
    {
		private Zoo zoo;
        private Dog dog;
        private Cat cat;

        [SetUp]
        public void SetUp()
        {
            zoo = new Zoo();
            dog = new Dog("Rex");
            cat = new Cat("Whiskers");
        }
		
        [Test]
        [Category("Zoo")]
        public void AddAnimal_ShouldAddAnimalToZoo()
        {
            zoo.AddAnimal(dog);
            Assert.Contains(dog, zoo.Animals);
        }

        [Test]
        [Category("Zoo")]
        public void AddAnimal_ShouldHandleMultipleAnimals()
        {
            zoo.AddAnimal(dog);
            zoo.AddAnimal(cat);

            Assert.Contains(dog, zoo.Animals);
            Assert.Contains(cat, zoo.Animals);
        }
    }
    
}
