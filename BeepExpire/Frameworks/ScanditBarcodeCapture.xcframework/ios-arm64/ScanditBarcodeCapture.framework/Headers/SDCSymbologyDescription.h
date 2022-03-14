/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2018- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>

#import <ScanditCaptureCore/SDCBase.h>
#import <ScanditBarcodeCapture/SDCSymbology.h>

NS_ASSUME_NONNULL_BEGIN

struct SDCRange {
    NSInteger minimum;
    NSInteger maximum;
    NSInteger step;
};
typedef struct __attribute__((objc_boxable)) SDCRange SDCRange;

// https://jira.scandit.com/browse/SDK-8770
// clang-format off
SDC_EXTERN BOOL SDCRangeIsFixed(SDCRange range) NS_SWIFT_NAME(getter:SDCRange.isFixed(self:));
// clang-format on

NS_SWIFT_NAME(SymbologyDescription)
SDC_EXPORTED_SYMBOL
@interface SDCSymbologyDescription : NSObject

@property (class, nonatomic, nonnull, readonly)
    NSArray<SDCSymbologyDescription *> *allSymbologyDescriptions NS_SWIFT_NAME(all);

@property (nonatomic, nonnull, readonly) NSString *identifier;
@property (nonatomic, nonnull, readonly) NSString *readableName;
@property (nonatomic, readonly) BOOL isAvailable;
@property (nonatomic, readonly) BOOL isColorInvertible;
@property (nonatomic, readonly) SDCRange activeSymbolCountRange;
@property (nonatomic, readonly) SDCRange defaultSymbolCountRange;
@property (nonatomic, nonnull, readonly) NSSet<NSString *> *supportedExtensions;
@property (nonatomic, readonly) SDCSymbology symbology;
@property (nonatomic, readonly) SDCChecksum supportedChecksums;
@property (nonatomic, nonnull, readonly) NSString *JSONString;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

+ (SDCSymbology)symbologyFromIdentifier:(nonnull NSString *)identifier
    DEPRECATED_MSG_ATTRIBUTE("Use symbologyDescriptionFromIdentifier: and symbology instead.");

+ (nullable SDCSymbologyDescription *)symbologyDescriptionFromIdentifier:
    (nonnull NSString *)identifier NS_SWIFT_NAME(init(identifier:));

- (nonnull instancetype)initWithSymbology:(SDCSymbology)symbology NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
