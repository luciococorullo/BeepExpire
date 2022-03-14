/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import <ScanditCaptureCore/SDCBase.h>

typedef NS_OPTIONS(NSUInteger, SDCChecksum) {
    SDCChecksumMod10 = 1 << 0,
    SDCChecksumMod11 = 1 << 1,
    SDCChecksumMod47 = 1 << 2,
    SDCChecksumMod103 = 1 << 3,
    SDCChecksumMod10AndMod10 = 1 << 4,
    SDCChecksumMod10AndMod11 = 1 << 5,
    SDCChecksumMod43 = 1 << 6,
    SDCChecksumMod16 = 1 << 7,
} NS_SWIFT_NAME(Checksum);

// clang-format off
typedef NS_CLOSED_ENUM(NSUInteger, SDCSymbology) {
    SDCSymbologyEAN13UPCA NS_SWIFT_NAME(ean13UPCA),
    SDCSymbologyUPCE NS_SWIFT_NAME(upce),
    SDCSymbologyEAN8 NS_SWIFT_NAME(ean8),
    SDCSymbologyCode39,
    SDCSymbologyCode93,
    SDCSymbologyCode128,
    SDCSymbologyCode11,
    SDCSymbologyCode25,
    SDCSymbologyCodabar,
    SDCSymbologyInterleavedTwoOfFive,
    SDCSymbologyMSIPlessey,
    SDCSymbologyQR NS_SWIFT_NAME(qr),
    SDCSymbologyDataMatrix,
    SDCSymbologyAztec,
    SDCSymbologyMaxiCode,
    SDCSymbologyDotCode,
    SDCSymbologyKIX NS_SWIFT_NAME(kix),
    SDCSymbologyRM4SCC NS_SWIFT_NAME(rm4scc),
    SDCSymbologyGS1Databar,
    SDCSymbologyGS1DatabarExpanded,
    SDCSymbologyGS1DatabarLimited,
    SDCSymbologyPDF417 NS_SWIFT_NAME(pdf417),
    SDCSymbologyMicroPDF417,
    SDCSymbologyMicroQR,
    SDCSymbologyCode32,
    SDCSymbologyLapa4SC,
    SDCSymbologyIATATwoOfFive,
    SDCSymbologyMatrixTwoOfFive,
    SDCSymbologyUSPSIntelligentMail
} NS_SWIFT_NAME(Symbology);
// clang-format on

// clang-format off
SDC_EXTERN NSString *_Nonnull SDCSymbologyToString(SDCSymbology symbology) NS_SWIFT_NAME(getter:SDCSymbology.description(self:));
// clang-format on

SDC_EXTERN NSArray<NSNumber *> *_Nonnull SDCAllSymbologies(void);
