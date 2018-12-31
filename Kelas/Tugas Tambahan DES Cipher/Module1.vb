Module Module1
    Sub Main()
        Console.WriteLine("Algoritma DES (Data Encryption Standard)")

        '1. Tentukan kalimat yang akan dienkrip
        Console.WriteLine("Masukkan kalimat yang akan dienkrip: ")
        Dim input As String = Console.ReadLine
        Console.WriteLine("")

        '2. Tentukan kata kunci enkripsi yang digunakan
        Console.WriteLine("Masukkan kata kunci enkripsi: ")
        Dim kataKunci As String = Console.ReadLine
        Console.WriteLine("")

        '3. Lakukan inisialisasi variabel yang digunakan oleh metode ini
        'Penjelasan lebih detail tentang fungsi ini dapat dilihat pada penjelasan skrip dibawah ini
        Dim xc As New CryptCore()
        xc.InitCore()
        xc.Key = kataKunci

        '4. Lakukan enkripsi kalimat awal menggunakan algoritma ini
        'Penjelasan lebih detail tentang fungsi ini dapat dilihat pada penjelasan skrip dibawah ini
        Dim hasilEnkripsi As String = xc.Encrypt(input)
        Console.WriteLine("Hasil enkripsi kalimat input adalah: " & vbCrLf & hasilEnkripsi.ToString & vbCrLf)

        '5. Lakukan dekripsi dari kalimat yang telah terenkripsi
        'Penjelasan lebih detail tentang fungsi ini dapat dilihat pada penjelasan skrip dibawah ini
        Dim hasilDekripsi As String = xc.Decrypt(hasilEnkripsi)
        Console.WriteLine("Hasil dekripsi dari kalimat terenkripsi adalah: " & vbCrLf & hasilDekripsi & vbCrLf)

        Console.ReadLine()
    End Sub
End Module

Public Class CryptCore
    Private _key As String = Nothing
    Public Property Key() As String
        Get
            Return _key
        End Get
        Set(value As String)
            _key = Me.formatKey(value)
        End Set
    End Property

    Private Function formatKey(key As String) As String
        If key Is Nothing OrElse key.Length = 0 Then
            Return Nothing
        End If
        Return key.Trim()
    End Function

    Private DefaultKey As String = ""

    Public Sub New()
        DefaultKey = "enkripsi"
    End Sub

    Private _coreSymmetric As CoreAlgoritmaSymmetric

    Public Function InitCore() As Boolean
        _coreSymmetric = New CoreAlgoritmaSymmetric()
        Return True
    End Function

    Public Function Decrypt(src As String) As String
        Dim hasil As String = ""

        If _key Is Nothing Then
            hasil = _coreSymmetric.ProsesDecrypt(src, DefaultKey)
        Else
            hasil = _coreSymmetric.ProsesDecrypt(src, _key)
        End If

        Return hasil
    End Function

    Public Function Decrypt(src As String, key As String) As String
        Dim hasil As String = ""

        hasil = _coreSymmetric.ProsesDecrypt(src, key)

        Return hasil
    End Function

    Public Function Encrypt(src As String) As String
        Dim hasil As String = ""

        If _key Is Nothing Then
            hasil = _coreSymmetric.ProsesEncrypt(src, DefaultKey)
        Else
            hasil = _coreSymmetric.ProsesEncrypt(src, _key)
        End If

        Return hasil
    End Function

    Public Function Encrypt(src As String, key As String) As String
        Dim hasil As String = ""

        hasil = _coreSymmetric.ProsesEncrypt(src, key)

        Return hasil
    End Function

    Public Class CoreAlgoritmaSymmetric
        Private metodeEncode As System.Security.Cryptography.SymmetricAlgorithm

        Public Sub New()
            metodeEncode = New System.Security.Cryptography.DESCryptoServiceProvider()
        End Sub

        Private Function GetValidKey(Key As String) As Byte()
            Dim sTemp As String
            If metodeEncode.LegalKeySizes.Length > 0 Then
                Dim lessSize As Integer = 0, moreSize As Integer = metodeEncode.LegalKeySizes(0).MinSize

                While Key.Length * 8 > moreSize AndAlso metodeEncode.LegalKeySizes(0).SkipSize > 0 AndAlso moreSize < metodeEncode.LegalKeySizes(0).MaxSize
                    lessSize = moreSize
                    moreSize += metodeEncode.LegalKeySizes(0).SkipSize
                End While

                If Key.Length * 8 > moreSize Then
                    sTemp = Key.Substring(0, (moreSize / 8))
                Else
                    sTemp = Key.PadRight(moreSize / 8, " "c)
                End If
            Else
                sTemp = Key
            End If

            'Konversi kata kunci menjadi byte array
            Return System.Text.ASCIIEncoding.ASCII.GetBytes(sTemp)
        End Function

        Private Function GetValidIV(InitVector As [String], panjangValid As Integer) As Byte()
            If InitVector.Length > panjangValid Then
                Return System.Text.ASCIIEncoding.ASCII.GetBytes(InitVector.Substring(0, panjangValid))
            Else
                Return System.Text.ASCIIEncoding.ASCII.GetBytes(InitVector.PadRight(panjangValid, " "c))
            End If
        End Function

        Public Function ProsesEncrypt(Source As String, Key As String) As String
            If Source Is Nothing OrElse Key Is Nothing OrElse Source.Length = 0 OrElse Key.Length = 0 Then
                Return Nothing
            End If

            If metodeEncode Is Nothing Then
                Return Nothing
            End If

            Dim lPanjangStream As Long
            Dim jumlahBufferTerbaca As Integer
            Dim byteBuffer As Byte() = New Byte(2) {}
            Dim srcData As Byte() = System.Text.ASCIIEncoding.ASCII.GetBytes(Source)
            Dim encData As Byte()
            Dim streamInput As New System.IO.MemoryStream()
            streamInput.Write(srcData, 0, srcData.Length)
            streamInput.Position = 0
            Dim streamOutput As New System.IO.MemoryStream()
            Dim streamEncrypt As System.Security.Cryptography.CryptoStream

            metodeEncode.Key = GetValidKey(Key)
            metodeEncode.IV = GetValidIV(Key, metodeEncode.IV.Length)

            streamEncrypt = New System.Security.Cryptography.CryptoStream(streamOutput, metodeEncode.CreateEncryptor(), System.Security.Cryptography.CryptoStreamMode.Write)
            lPanjangStream = streamInput.Length

            Dim totalBufferTerbaca As Integer = 0
            While totalBufferTerbaca < lPanjangStream
                jumlahBufferTerbaca = streamInput.Read(byteBuffer, 0, byteBuffer.Length)
                streamEncrypt.Write(byteBuffer, 0, jumlahBufferTerbaca)
                totalBufferTerbaca += jumlahBufferTerbaca
            End While
            streamEncrypt.Close()

            encData = streamOutput.ToArray()

            'Konversi menjadi base64 agar hasil dapat digunakan dalam xml
            Return Convert.ToBase64String(encData)
        End Function

        Public Function ProsesDecrypt(Source As String, Key As String) As String
            If Source Is Nothing OrElse Key Is Nothing OrElse Source.Length = 0 OrElse Key.Length = 0 Then
                Return Nothing
            End If

            If metodeEncode Is Nothing Then
                Return Nothing
            End If

            Dim lPanjangStream As Long
            Dim jumlahBufferTerbaca As Integer
            Dim byteBuffer As Byte() = New Byte(2) {}
            Dim encData As Byte() = Convert.FromBase64String(Source)
            Dim decData As Byte()
            Dim streamInput As New System.IO.MemoryStream(encData)
            Dim streamOutput As New System.IO.MemoryStream()
            Dim streamDecrypt As System.Security.Cryptography.CryptoStream

            metodeEncode.Key = GetValidKey(Key)
            metodeEncode.IV = GetValidIV(Key, metodeEncode.IV.Length)

            streamDecrypt = New System.Security.Cryptography.CryptoStream(streamInput, metodeEncode.CreateDecryptor(), System.Security.Cryptography.CryptoStreamMode.Read)
            lPanjangStream = streamInput.Length

            Dim totalBufferTerbaca As Integer = 0
            While totalBufferTerbaca < lPanjangStream
                jumlahBufferTerbaca = streamDecrypt.Read(byteBuffer, 0, byteBuffer.Length)
                If 0 = jumlahBufferTerbaca Then
                    Exit While
                End If

                streamOutput.Write(byteBuffer, 0, jumlahBufferTerbaca)
                totalBufferTerbaca += jumlahBufferTerbaca
            End While
            streamDecrypt.Close()

            decData = streamOutput.ToArray()
            For i As Integer = 0 To decData.Length - 1
                If decData(i) < 8 Then decData(i) = 0
            Next

            Dim encodeASCII As New System.Text.ASCIIEncoding()
            Return encodeASCII.GetString(decData)
        End Function
    End Class
End Class
