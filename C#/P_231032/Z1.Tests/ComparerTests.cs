using NUnit.Framework;
using System;
using System.Collections.Generic;
using System.Text;
using Z1;

using static Z1.Animal;
namespace Z1.Tests
{
    
    [TestFixture]
    public class ComparerTests
    {
        private AnimalNameLengthComparer comparer;

        [SetUp]
        public void SetUp()
        {
            comparer = new AnimalNameLengthComparer();
        }

        [Test]
        [Category("Comparer")]
        public void Compare_ShouldReturnZero_WhenNamesHaveSameLength()
        {
            Animal dog = new Dog("Rex");
            Animal cat = new Cat("Max");

            int result = comparer.Compare(dog, cat);

            Assert.AreEqual(0, result);
        }

        [Test]
        [Category("Comparer")]
        public void Compare_ShouldReturnNegative_WhenFirstNameIsShorter()
        {
            Animal dog = new Dog("Rex");
            Animal cat = new Cat("Whiskers");

            int result = comparer.Compare(dog, cat);

            Assert.Less(result, 0);
        }

        [Test]
        [Category("Comparer")]
        public void Compare_ShouldReturnPositive_WhenFirstNameIsLonger()
        {
            Animal dog = new Dog("Maximus");
            Animal cat = new Cat("Cat");

            int result = comparer.Compare(dog, cat);

            Assert.Greater(result, 0);
        }

        [Test]
        [Category("Comparer")]
        public void Compare_ShouldHandleNullValues_Gracefully()
        {
            Animal dog = new Dog("Rex");
            Animal nullAnimal = null;

            Assert.Throws<ArgumentNullException>(() => comparer.Compare(dog, nullAnimal));
            Assert.Throws<ArgumentNullException>(() => comparer.Compare(nullAnimal, dog));
            Assert.Throws<ArgumentNullException>(() => comparer.Compare(nullAnimal, nullAnimal));
        }
    }
    
}
