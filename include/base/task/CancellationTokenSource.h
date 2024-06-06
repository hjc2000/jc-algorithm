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
}
