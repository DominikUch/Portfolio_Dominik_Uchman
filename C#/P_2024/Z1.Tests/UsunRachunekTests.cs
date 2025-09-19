
using NUnit.Framework;
using Z1;
namespace Z1.Tests
{
    [TestFixture]
    class UsunRachunekTests
    {
        [Test]
        [Category("UsuñRachunek")]
        public void UsunRachunek_RachunekIstnieje_UsuwaRachunekIZwracaTrue()
        {
            // Arrange
            var systemBankowy = new SystemBankowy();
            var rachunek = new RachunekOsobisty("123456", "Jan Kowalski");
            systemBankowy.DodajRachunek(rachunek);

            // Act
            bool wynik = systemBankowy.UsunRachunek(rachunek);

            // Assert
            Assert.IsTrue(wynik);
            Assert.IsFalse(systemBankowy.RachunkiBankowe.Contains(rachunek));
        }

        [Test]
        [Category("UsuñRachunek")]
        public void UsunRachunek_RachunekNieIstnieje_ZwracaFalse()
        {
            // Arrange
            var systemBankowy = new SystemBankowy();
            var rachunek = new RachunekOsobisty("123456", "Jan Kowalski");

            // Act
            bool wynik = systemBankowy.UsunRachunek(rachunek);

            // Assert
            Assert.IsFalse(wynik);
            Assert.IsFalse(systemBankowy.RachunkiBankowe.Contains(rachunek));
        }
    }
}
