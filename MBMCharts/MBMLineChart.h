//
//  MBMLineChart.h
//  MBMCharts
//
//  Created by Pat Murphy on 12/14/12.
//  Copyright (c) 2012 Pat Murphy. All rights reserved.
//

#import <Foundation/Foundation.h>

@class MBMLineChart;
@protocol MBMLineChartDataSource <NSObject>
@required
- (NSUInteger)numberOfLinesInChart:(MBMLineChart *)lineChart;
- (CGFloat)lineChart:(MBMLineChart *)lineChart valueForLineAtIndex:(NSUInteger)index;
- (CGPoint)lineChart:(MBMLineChart *)lineChart pointForLineAtIndex:(NSUInteger)index;
@optional
- (UIColor *)lineChart:(MBMLineChart *)lineChart colorForLineAtIndex:(NSUInteger)index;
- (NSString *)lineChart:(MBMLineChart *)lineChart textForLineAtIndex:(NSUInteger)index;
@end

@protocol MBMLineChartDelegate <NSObject>
@optional
- (void)lineChart:(MBMLineChart *)lineChart willSelectLineAtIndex:(NSUInteger)index;
- (void)lineChart:(MBMLineChart *)lineChart didSelectLineAtIndex:(NSUInteger)index;
- (void)lineChart:(MBMLineChart *)lineChart willDeselectLineAtIndex:(NSUInteger)index;
- (void)lineChart:(MBMLineChart *)lineChart didDeselectLineAtIndex:(NSUInteger)index;
@end

@interface MBMLineChart : UIView
@property (nonatomic, assign) id<MBMLineChartDataSource> dataSource;
@property (nonatomic, assign) id<MBMLineChartDelegate> delegate;
@property (nonatomic, assign) CGPoint linePoint;
@property (nonatomic, assign) CGFloat animationSpeed;
@property (nonatomic, assign) CGFloat lineHeight;
@property (nonatomic, assign) CGFloat lineRadius;
@property (nonatomic, assign) CGFloat numberOfLines;
@property (nonatomic, assign) NSUInteger numberOfElements;
@property (nonatomic, assign) BOOL    showLabel;
@property (nonatomic, retain) UIFont  *labelFont;
@property (nonatomic, retain) UIColor *labelColor;
@property (nonatomic, retain) UIColor *labelShadowColor;
@property (nonatomic, assign) CGFloat selectedLineStroke;
@property (nonatomic, retain) NSMutableArray *lineDicArray;
@property (nonatomic, assign) CGRect chartRect;
@property (nonatomic, assign) CGFloat paddingTop;
@property (nonatomic, assign) CGFloat paddingBotom;
@property (nonatomic, assign) CGFloat leftPadding;
@property (nonatomic, assign) CGFloat stepWidthAxisY;
@property (nonatomic, assign) CGSize labelSizeAxisY;
@property (nonatomic, assign) CGFloat maxValueAxisY;
@property (nonatomic, assign) CGFloat minValueAxisY;
@property (nonatomic, assign) CGFloat stepValueAxisY;
@property (nonatomic, assign) CGFloat barFullWidth;
@property (nonatomic, assign) CGFloat fontSize;
@property (nonatomic, assign) CGFloat barLabelFontSize;
@property (nonatomic, assign) CGFloat barWidth;
@property (nonatomic, assign) CGFloat barInterval;
@property (nonatomic, assign) CGFloat maxValue;
@property (nonatomic, assign) CGFloat scaleAxisY;
@property (nonatomic, retain) UIColor *colorAxisY;
@property (nonatomic, retain) UIColor *colorAxis;
@property (nonatomic, assign) BOOL showAxisY;
@property (nonatomic, assign) BOOL showAxisX;
@property (nonatomic, assign) BOOL plotVerticalLines;
@property (nonatomic, assign) BOOL addHorizontalLabels;

- (void)reloadData;
- (void)setLineBackgroundColor:(UIColor *)color;
- (void)calculateChartFrame;
- (void)drawChart:(NSMutableArray*)lineDicArray;

@end

