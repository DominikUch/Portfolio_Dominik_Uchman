using NUnit.Framework;
using System;
using System.Collections.Generic;
using System.Text;
using Z1;

namespace Z1.Tests
{
    
    [TestFixture]
    public class CatConstructorTests
    {
        [Test]
        [Category("CatConstructor")]
        public void Cat_Name_ShouldBeSetCorrectly()
        {
            Cat cat = new Cat("Whiskers");
            Assert.AreEqual("Whiskers", cat.Name);
        }
    }
    
}
