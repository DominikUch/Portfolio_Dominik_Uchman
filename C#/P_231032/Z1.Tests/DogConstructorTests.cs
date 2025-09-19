using NUnit.Framework;
using System;
using System.Collections.Generic;
using System.Text;
using Z1;

namespace Z1.Tests
{
    
    [TestFixture]
    public class DogConstructorTests
    {
        [Test]
        [Category("DogConstructor")]
        public void Dog_Name_ShouldBeSetCorrectly()
        {
            Dog dog = new Dog("Rex");
            Assert.AreEqual("Rex", dog.Name);
        }
    }
    
}
