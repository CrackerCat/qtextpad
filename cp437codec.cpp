/* This file is part of QTextPad.
 *
 * QTextPad is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * QTextPad is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with QTextPad.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "charsets.h"

static const ushort cp437_map[128] = {
    0x00C7, 0x00FC, 0x00E9, 0x00E2, 0x00E4, 0x00E0, 0x00E5, 0x00E7,
    0x00EA, 0x00EB, 0x00E8, 0x00EF, 0x00EE, 0x00EC, 0x00C4, 0x00C5,
    0x00C9, 0x00E6, 0x00C6, 0x00F4, 0x00F6, 0x00F2, 0x00FB, 0x00F9,
    0x00FF, 0x00D6, 0x00DC, 0x00A2, 0x00A3, 0x00A5, 0x20A7, 0x0192,
    0x00E1, 0x00ED, 0x00F3, 0x00FA, 0x00F1, 0x00D1, 0x00AA, 0x00BA,
    0x00BF, 0x2310, 0x00AC, 0x00BD, 0x00BC, 0x00A1, 0x00AB, 0x00BB,
    0x2591, 0x2592, 0x2593, 0x2502, 0x2524, 0x2561, 0x2562, 0x2556,
    0x2555, 0x2563, 0x2551, 0x2557, 0x255D, 0x255C, 0x255B, 0x2510,
    0x2514, 0x2534, 0x252C, 0x251C, 0x2500, 0x253C, 0x255E, 0x255F,
    0x255A, 0x2554, 0x2569, 0x2566, 0x2560, 0x2550, 0x256C, 0x2567,
    0x2568, 0x2564, 0x2565, 0x2559, 0x2558, 0x2552, 0x2553, 0x256B,
    0x256A, 0x2518, 0x250C, 0x2588, 0x2584, 0x258C, 0x2590, 0x2580,
    0x03B1, 0x00DF, 0x0393, 0x03C0, 0x03A3, 0x03C3, 0x00B5, 0x03C4,
    0x03A6, 0x0398, 0x03A9, 0x03B4, 0x221E, 0x03C6, 0x03B5, 0x2229,
    0x2261, 0x00B1, 0x2265, 0x2264, 0x2320, 0x2321, 0x00F7, 0x2248,
    0x00B0, 0x2219, 0x00B7, 0x221A, 0x207F, 0x00B2, 0x25A0, 0x00A0,
};

static int to_cp437(ushort unichar)
{
    // Probably more efficient than building a map...
    switch (unichar) {
    case 0x00C7:  return 0x80;
    case 0x00FC:  return 0x81;
    case 0x00E9:  return 0x82;
    case 0x00E2:  return 0x83;
    case 0x00E4:  return 0x84;
    case 0x00E0:  return 0x85;
    case 0x00E5:  return 0x86;
    case 0x00E7:  return 0x87;
    case 0x00EA:  return 0x88;
    case 0x00EB:  return 0x89;
    case 0x00E8:  return 0x8A;
    case 0x00EF:  return 0x8B;
    case 0x00EE:  return 0x8C;
    case 0x00EC:  return 0x8D;
    case 0x00C4:  return 0x8E;
    case 0x00C5:  return 0x8F;
    case 0x00C9:  return 0x90;
    case 0x00E6:  return 0x91;
    case 0x00C6:  return 0x92;
    case 0x00F4:  return 0x93;
    case 0x00F6:  return 0x94;
    case 0x00F2:  return 0x95;
    case 0x00FB:  return 0x96;
    case 0x00F9:  return 0x97;
    case 0x00FF:  return 0x98;
    case 0x00D6:  return 0x99;
    case 0x00DC:  return 0x9A;
    case 0x00A2:  return 0x9B;
    case 0x00A3:  return 0x9C;
    case 0x00A5:  return 0x9D;
    case 0x20A7:  return 0x9E;
    case 0x0192:  return 0x9F;
    case 0x00E1:  return 0xA0;
    case 0x00ED:  return 0xA1;
    case 0x00F3:  return 0xA2;
    case 0x00FA:  return 0xA3;
    case 0x00F1:  return 0xA4;
    case 0x00D1:  return 0xA5;
    case 0x00AA:  return 0xA6;
    case 0x00BA:  return 0xA7;
    case 0x00BF:  return 0xA8;
    case 0x2310:  return 0xA9;
    case 0x00AC:  return 0xAA;
    case 0x00BD:  return 0xAB;
    case 0x00BC:  return 0xAC;
    case 0x00A1:  return 0xAD;
    case 0x00AB:  return 0xAE;
    case 0x00BB:  return 0xAF;
    case 0x2591:  return 0xB0;
    case 0x2592:  return 0xB1;
    case 0x2593:  return 0xB2;
    case 0x2502:  return 0xB3;
    case 0x2524:  return 0xB4;
    case 0x2561:  return 0xB5;
    case 0x2562:  return 0xB6;
    case 0x2556:  return 0xB7;
    case 0x2555:  return 0xB8;
    case 0x2563:  return 0xB9;
    case 0x2551:  return 0xBA;
    case 0x2557:  return 0xBB;
    case 0x255D:  return 0xBC;
    case 0x255C:  return 0xBD;
    case 0x255B:  return 0xBE;
    case 0x2510:  return 0xBF;
    case 0x2514:  return 0xC0;
    case 0x2534:  return 0xC1;
    case 0x252C:  return 0xC2;
    case 0x251C:  return 0xC3;
    case 0x2500:  return 0xC4;
    case 0x253C:  return 0xC5;
    case 0x255E:  return 0xC6;
    case 0x255F:  return 0xC7;
    case 0x255A:  return 0xC8;
    case 0x2554:  return 0xC9;
    case 0x2569:  return 0xCA;
    case 0x2566:  return 0xCB;
    case 0x2560:  return 0xCC;
    case 0x2550:  return 0xCD;
    case 0x256C:  return 0xCE;
    case 0x2567:  return 0xCF;
    case 0x2568:  return 0xD0;
    case 0x2564:  return 0xD1;
    case 0x2565:  return 0xD2;
    case 0x2559:  return 0xD3;
    case 0x2558:  return 0xD4;
    case 0x2552:  return 0xD5;
    case 0x2553:  return 0xD6;
    case 0x256B:  return 0xD7;
    case 0x256A:  return 0xD8;
    case 0x2518:  return 0xD9;
    case 0x250C:  return 0xDA;
    case 0x2588:  return 0xDB;
    case 0x2584:  return 0xDC;
    case 0x258C:  return 0xDD;
    case 0x2590:  return 0xDE;
    case 0x2580:  return 0xDF;
    case 0x03B1:  return 0xE0;
    case 0x00DF:  return 0xE1;
    case 0x0393:  return 0xE2;
    case 0x03C0:  return 0xE3;
    case 0x03A3:  return 0xE4;
    case 0x03C3:  return 0xE5;
    case 0x00B5:  return 0xE6;
    case 0x03C4:  return 0xE7;
    case 0x03A6:  return 0xE8;
    case 0x0398:  return 0xE9;
    case 0x03A9:  return 0xEA;
    case 0x03B4:  return 0xEB;
    case 0x221E:  return 0xEC;
    case 0x03C6:  return 0xED;
    case 0x03B5:  return 0xEE;
    case 0x2229:  return 0xEF;
    case 0x2261:  return 0xF0;
    case 0x00B1:  return 0xF1;
    case 0x2265:  return 0xF2;
    case 0x2264:  return 0xF3;
    case 0x2320:  return 0xF4;
    case 0x2321:  return 0xF5;
    case 0x00F7:  return 0xF6;
    case 0x2248:  return 0xF7;
    case 0x00B0:  return 0xF8;
    case 0x2219:  return 0xF9;
    case 0x00B7:  return 0xFA;
    case 0x221A:  return 0xFB;
    case 0x207F:  return 0xFC;
    case 0x00B2:  return 0xFD;
    case 0x25A0:  return 0xFE;
    case 0x00A0:  return 0xFF;
    default:
        return -1;
    }
}

QString Cp437Codec::convertToUnicode(const char *in, int length, ConverterState *) const
{
    if (!in || length <= 0)
        return QString();

    QString conv;
    conv.resize(length);
    QChar *dp = conv.data();
    for (int i = 0; i < length; ++i) {
        if (static_cast<uint8_t>(in[i]) < 128)
            *dp++ = QLatin1Char(in[i]);
        else
            *dp++ = cp437_map[static_cast<uint8_t>(in[i]) - 128];
    }
    return conv;
}

QByteArray Cp437Codec::convertFromUnicode(const QChar *in, int length, ConverterState *state) const
{
    const char substitute = (state && (state->flags & ConvertInvalidToNull) != 0) ? 0 : '?';
    int numInvalid = 0;

    QByteArray conv;
    conv.resize(length);
    char *dp = conv.data();
    for (int i = 0; i < length; ++i) {
        if (in[i].unicode() < 128) {
            *dp++ = static_cast<char>(in[i].unicode());
        } else {
            int ch = to_cp437(in[i].unicode());
            if (ch >= 0) {
                *dp++ = static_cast<char>(ch);
            } else {
                *dp++ = substitute;
                ++numInvalid;
            }
        }
    }

    if (state)
        state->invalidChars += numInvalid;
    return conv;
}
