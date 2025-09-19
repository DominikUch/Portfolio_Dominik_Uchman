
using NUnit.Framework;
using Z1;
namespace Z1.Tests
{
    [TestFixture]
    class IndeksatorTests
    {
        [Test]
        [Category("Indeksator")]
        public void Indeksator_ZnajdujeRachunekNaPodstawieNumeru()
        {
            // Arrange
            var systemBankowy = new SystemBankowy();
            var rachunek1 = new RachunekOsobisty("123456", "Jan Kowalski");
            var rachunek2 = new RachunekFirmowy("654321", "Anna Nowak", "Firma XYZ");
            systemBankowy.RachunkiBankowe.Add(rachunek1);
            systemBankowy.RachunkiBankowe.Add(rachunek2);

            // Act
            var znalezionyRachunek = systemBankowy["123456"];

            // Assert
            Assert.IsNotNull(znalezionyRachunek);
            Assert.AreEqual(rachunek1, znalezionyRachunek);
        }

        [Test]
        [Category("Indeksator")]
        public void Indeksator_ZwracaNullDlaNieistniejacegoNumeruRachunku()
        {
            // Arrange
            var systemBankowy = new SystemBankowy();
            var rachunek1 = new RachunekOsobisty("123456", "Jan Kowalski");
            systemBankowy.RachunkiBankowe.Add(rachunek1);

            // Act
            var znalezionyRachunek = systemBankowy["999999"];

            // Assert
            Assert.IsNull(znalezionyRachunek);
        }
    }
}
