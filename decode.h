﻿#ifndef DECODE_H
#define DECODE_H

struct AVCodecParameters;
struct AVCodecContext;
struct AudioSwrSpec;
struct VideoSwsSpec;
struct AVPacket;
struct AVFrame;
struct AVCodec;
struct AVStream;

class Decode
{
public:
    Decode();

    /**
     * @brief Decode::Open  根据配置参数初始化并打开解码器
     * @param par           解码器参数
     * @return 0 on success, otherwise negative
     */
    int Open(AVCodecParameters*  par, AVStream*);

    /**
     * @brief GetAudioCodecSpec 获取解码器音频配置参数
     * @return AudioSwrSpec
     */
    AudioSwrSpec* GetAudioCodecSpec();

    /**
     * @brief GetVideoCodecSpec 获取解码器视频配置参数
     * @return VideoSwsSpec
     */
    VideoSwsSpec* GetVideoCodecSpec();

    /**
     * @brief SendPkt   将AVPacket 发送给解码器
     * @param pkt
     * @return 0 on success, otherwise negative
     */
    int SendPkt(AVPacket *pkt);

    /**
     * @brief RecvFrame 获取解码后的数据
     * @return
     */
    AVFrame* RecvFrame();

    double synchronize(AVFrame *srcFrame, double pts);

private:

    AVCodec* m_codec;

    AVCodecContext* m_decodeCtx;

    AVStream *stream;
};

#endif // DECODE_H
