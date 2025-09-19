
using NUnit.Framework;
using System;
using System.Collections.Generic;
using System.Text;
using Z1;
namespace Z1.Tests
{
    [TestFixture]
    public class RefleksjaTests
    {
        [Test]
		[Category("RefleksjaTests")]
        public void OdczytajPolePrywatne_ZwracaPoprawnaWartosc()
        {
            // Arrange
            RachunekFirmowy rachunekFirmowy = new RachunekFirmowy("123456789", "Jan Kowalski", "Firma XYZ");

            // Act
            string nazwaFirmy = Refleksja.OdczytajPolePrywatne(rachunekFirmowy);

            // Assert
            Assert.AreEqual("Firma XYZ", nazwaFirmy);
        }

        [Test]
		[Category("RefleksjaTests")]
        public void OdczytajPolePrywatne_DlaPustegoObiektu_ZwracaNull()
        {
            // Arrange
            RachunekFirmowy rachunekFirmowy = new RachunekFirmowy("123456789", "Jan Kowalski", "");

            // Act
            string nazwaFirmy = Refleksja.OdczytajPolePrywatne(rachunekFirmowy);

            // Assert
            Assert.AreEqual("", nazwaFirmy);
        }

        [Test]
		[Category("RefleksjaTests")]
        public void OdczytajPolePrywatne_DlaObiektuBezNazwyFirmy_ZwracaNull()
        {
            // Arrange
            RachunekFirmowy rachunekFirmowy = new RachunekFirmowy("123456789", "Jan Kowalski", null);

            // Act
            string nazwaFirmy = Refleksja.OdczytajPolePrywatne(rachunekFirmowy);

            // Assert
            Assert.IsNull(nazwaFirmy);
        }

        [Test]
		[Category("RefleksjaTests")]
        public void OdczytajPolePrywatne_DlaPustegoPola_WyrzucaWyjatek()
        {
            // Arrange
            RachunekFirmowy rachunekFirmowy = new RachunekFirmowy("123456789", "Jan Kowalski", "Firma XYZ");
            rachunekFirmowy = null;

            // Act & Assert
            Assert.Throws<ArgumentNullException>(() => Refleksja.OdczytajPolePrywatne(rachunekFirmowy));
        }
    }
}
