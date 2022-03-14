/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2020- Scandit AG. All rights reserved.
 */

#import <ScanditCaptureCore/SDCBase.h>
#import <ScanditBarcodeCapture/SDCSymbology.h>

@class SDCSymbologySettings;

@protocol SDCBarcodeSelectionType;

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(BarcodeSelectionSettings)
SDC_EXPORTED_SYMBOL
@interface SDCBarcodeSelectionSettings : NSObject <NSCopying>

@property (nonatomic, nonnull, readonly)
    NSSet<NSNumber *> *enabledSymbologies NS_SWIFT_NAME(enabledSymbologyValues);
@property (nonatomic, assign) NSTimeInterval codeDuplicateFilter;
@property (nonatomic, assign) BOOL singleBarcodeAutoDetection;
@property (nonatomic, nonnull, retain) id<SDCBarcodeSelectionType> selectionType;

+ (instancetype)settings;

- (nonnull SDCSymbologySettings *)settingsForSymbology:(SDCSymbology)symbology;

- (void)enableSymbologies:(nonnull NSSet<NSNumber *> *)symbologies;
- (void)setSymbology:(SDCSymbology)symbology
             enabled:(BOOL)enabled NS_SWIFT_NAME(set(symbology:enabled:));

- (void)setValue:(id)value forProperty:(NSString *)property NS_SWIFT_NAME(set(value:forProperty:));
- (nullable id)valueForProperty:(NSString *)property;

@end

NS_ASSUME_NONNULL_END
