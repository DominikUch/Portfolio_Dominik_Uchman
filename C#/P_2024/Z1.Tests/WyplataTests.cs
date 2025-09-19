
using NUnit.Framework;
using System.Reflection;
using Z1;
namespace Z1.Tests
{
    [TestFixture]
    class WyplataTests
    {
        FieldInfo saldoRef = typeof(RachunekBankowy).GetField("saldo", BindingFlags.NonPublic | BindingFlags.Instance);

        [Test]
        [Category("Wyp�ata")]
        public void Wyp�ata_PoprawnaKwota_Wyp�ataWykonanaPoprawnie()
        {
            // Arrange
            RachunekBankowy rachunek = new RachunekOsobisty("123456789", "Jan Kowalski");

            // Act
            var res = rachunek.Wp�a�(100);
            rachunek.Wyp�a�(100);

            // Assert
            decimal saldoKo�cowe = (decimal)saldoRef.GetValue(rachunek);
            Assert.AreEqual(0, saldoKo�cowe);
            Assert.IsTrue(res);
        }

        [Test]
        [Category("Wyp�ata")]
        public void Wyp�ata_NiepoprawnaKwota_B��dBraku�rodk�w()
        {
            // Arrange
            RachunekBankowy rachunek = new RachunekOsobisty("123456789", "Jan Kowalski");
            decimal saldoPocz�tkowe = (decimal)saldoRef.GetValue(rachunek);
            decimal kwota = 1000;

            // Act
            var res = rachunek.Wyp�a�(kwota);

            // Assert
            decimal saldoKo�cowe = (decimal)saldoRef.GetValue(rachunek);
            Assert.AreEqual(saldoPocz�tkowe, saldoKo�cowe);
            Assert.IsFalse(res);
        }

        [Test]
        [Category("Wyp�ata")]
        public void Wyp�ata_NiepoprawnaKwota_B��dPr�baWyp�atyZaPomoc�UjemnejKwoty()
        {
            // Arrange
            RachunekBankowy rachunek = new RachunekOsobisty("123456789", "Jan Kowalski");
            decimal saldoPocz�tkowe = (decimal)saldoRef.GetValue(rachunek);
            decimal kwota = -50;

            // Act
            var res = rachunek.Wyp�a�(kwota);

            // Assert
            decimal saldoKo�cowe = (decimal)saldoRef.GetValue(rachunek);
            Assert.AreEqual(saldoPocz�tkowe, saldoKo�cowe);
            Assert.IsFalse(res);
        }
    }
}
