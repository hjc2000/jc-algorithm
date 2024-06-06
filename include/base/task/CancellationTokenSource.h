#pragma once
#include<base/task/CancellationToken.h>

namespace base
{
	/// <summary>
	///		取消令牌源
	/// </summary>
	class CancellationTokenSource
	{
	private:
		std::shared_ptr<CancellationToken> _token { new CancellationToken { } };

	public:
		bool IsCancellationRequested();
		std::shared_ptr<CancellationToken> Token() const;
		void Cancel();
	};

	/// <summary>
	///		任务取消后抛出此异常。
	///		* 建议抛出，因为这有助于帮助后台线程停下来。
	/// </summary>
	class TaskCanceledException :public std::runtime_error
	{
	public:
		TaskCanceledException() :runtime_error(__func__) { }
		TaskCanceledException(const char *msg) :runtime_error(std::string(__func__) + " " + msg) { }
		TaskCanceledException(std::string msg) :runtime_error(std::string(__func__) + " " + msg) { }
	};
}
