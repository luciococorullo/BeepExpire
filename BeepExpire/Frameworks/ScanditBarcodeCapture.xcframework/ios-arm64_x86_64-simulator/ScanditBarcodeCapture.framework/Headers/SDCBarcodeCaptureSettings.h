/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>

#import <ScanditCaptureCore/SDCBase.h>
#import <ScanditBarcodeCapture/SDCSymbology.h>
#import <ScanditBarcodeCapture/SDCCompositeType.h>

@class SDCSymbologySettings;
@protocol SDCLocationSelection;

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(BarcodeCaptureSettings)
SDC_EXPORTED_SYMBOL
@interface SDCBarcodeCaptureSettings : NSObject <NSCopying>

@property (nonatomic, assign) NSTimeInterval codeDuplicateFilter;

@property (nonatomic, nonnull, readonly)
    NSSet<NSNumber *> *enabledSymbologies NS_SWIFT_NAME(enabledSymbologyValues);

@property (nonatomic, strong, nullable) id<SDCLocationSelection> locationSelection;

@property (nonatomic, assign) SDCCompositeType enabledCompositeTypes;

+ (instancetype)settings;

- (nonnull SDCSymbologySettings *)settingsForSymbology:(SDCSymbology)symbology;

- (void)setValue:(id)value forProperty:(NSString *)property NS_SWIFT_NAME(set(value:forProperty:));

- (nullable id)valueForProperty:(NSString *)property;

- (void)enableSymbologies:(nonnull NSSet<NSNumber *> *)symbologies;

- (void)enableSymbologiesForCompositeTypes:(SDCCompositeType)types;

- (void)setSymbology:(SDCSymbology)symbology
             enabled:(BOOL)enabled NS_SWIFT_NAME(set(symbology:enabled:));

@end

NS_ASSUME_NONNULL_END
