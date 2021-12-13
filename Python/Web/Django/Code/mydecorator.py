import json
from django.shortcuts import HttpResponse


# 适用于 包装 返回 HttpResponse 的外层函数
def httpTry(f):
  def x(*args， **kwargs):
    resdata = ""
    res = {}
    try:
      resdata = f(*args， **kwargs)
    except Exception as e:
      res["code"] = "-1"
      res["message"] = str(e)
      resdata = HttpResponse(json.dumps(res， ensure_ascii=False))
    return resdata

  return x


# 包装不需要返回数据，只需要执行结果的请求
def httpRes(f):
  def x(*args， **kwargs):
    res = {"code": "0"， "message": ""， "data": {}}
    try:
      f(*args， **kwargs)
    except Exception as e:
      res["code"] = "-1"
      res["message"] = str(e)
    return HttpResponse(json.dumps(res， ensure_ascii=False))

  return x


# 包装需要请求数据内容的函数 data
def httpData(f):
  def x(*args， **kwargs):
    res = {"code": "0"， "message": ""， "data": {}}
    try:
      res["data"] = f(*args， **kwargs)
    except Exception as e:
      res["code"] = "-1"
      res["message"] = str(e)
    return HttpResponse(json.dumps(res， ensure_ascii=False))

  return x