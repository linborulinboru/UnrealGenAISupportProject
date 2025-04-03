import unreal
import sys
import os

# 添加插件Python目錄到路徑
plugin_path = os.path.join(unreal.Paths.project_plugins_dir(), "GenerativeAISupport/Content/Python")
sys.path.append(plugin_path)

# 導入socket服務器並啟動
try:
    import unreal_socket_server
    unreal_socket_server.start_socket_server()
    unreal.log("MCP 服務器已成功啟動!")
except Exception as e:
    unreal.log_error(f"啟動MCP服務器時發生錯誤: {str(e)}")

    # 顯示更多診斷信息
    unreal.log(f"Python路徑:")
    for path in sys.path:
        unreal.log(f"  {path}")

    if os.path.exists(plugin_path):
        unreal.log(f"插件目錄存在: {plugin_path}")
        files = os.listdir(plugin_path)
        unreal.log(f"目錄內容: {files}")
    else:
        unreal.log(f"插件目錄不存在: {plugin_path}")

unreal.log("MCP啟動腳本執行完畢")