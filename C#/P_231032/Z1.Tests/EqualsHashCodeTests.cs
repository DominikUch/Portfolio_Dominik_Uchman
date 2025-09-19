
using NUnit.Framework;
using System;
using System.Collections.Generic;
using System.Text;
using Z1;
namespace Z1.Tests
{
    
    [TestFixture]
    public class EqualsHashCodeTests
    {
        [Test]
        [Category("EqualsHashCode")]
        public void Animal_Equals_ShouldReturnTrue_WhenNamesAreEqual()
        {
            Animal animal1 = new Dog("Max");
            Animal animal2 = new Dog("Max");

            Assert.IsTrue(animal1.Equals(animal2));
        }

        [Test]
        [Category("EqualsHashCode")]
        public void Animal_Equals_ShouldReturnFalse_WhenNamesAreDifferent()
        {
            Animal animal1 = new Dog("Max");
            Animal animal2 = new Dog("Charlie");

            Assert.IsFalse(animal1.Equals(animal2));
        }

        [Test]
        [Category("EqualsHashCode")]
        public void Animal_GetHashCode_ShouldReturnSameValue_ForEqualObjects()
        {
            Animal animal1 = new Dog("Max");
            Animal animal2 = new Dog("Max");

            Assert.AreEqual(animal1.GetHashCode(), animal2.GetHashCode());
        }

        [Test]
        [Category("EqualsHashCode")]
        public void Animal_GetHashCode_ShouldReturnDifferentValues_ForDifferentObjects()
        {
            Animal animal1 = new Dog("Max");
            Animal animal2 = new Dog("Charlie");

            Assert.AreNotEqual(animal1.GetHashCode(), animal2.GetHashCode());
        }
		
		[Test]
        [Category("EqualsHashCode")]
        public void Cat_Equals_ShouldReturnTrue_WhenNamesAreEqual()
        {
            Cat cat1 = new Cat("Whiskers");
            Cat cat2 = new Cat("Whiskers");

            Assert.IsTrue(cat1.Equals(cat2));
        }

        [Test]
        [Category("EqualsHashCode")]
        public void Cat_Equals_ShouldReturnFalse_WhenNamesAreDifferent()
        {
            Cat cat1 = new Cat("Whiskers");
            Cat cat2 = new Cat("Bella");

            Assert.IsFalse(cat1.Equals(cat2));
        }

        [Test]
        [Category("EqualsHashCode")]
        public void Cat_GetHashCode_ShouldReturnSameValue_ForEqualObjects()
        {
            Cat cat1 = new Cat("Whiskers");
            Cat cat2 = new Cat("Whiskers");

            Assert.AreEqual(cat1.GetHashCode(), cat2.GetHashCode());
        }

        [Test]
        [Category("EqualsHashCode")]
        public void Cat_GetHashCode_ShouldReturnDifferentValues_ForDifferentObjects()
        {
            Cat cat1 = new Cat("Whiskers");
            Cat cat2 = new Cat("Bella");

            Assert.AreNotEqual(cat1.GetHashCode(), cat2.GetHashCode());
        }
    }
    
}


